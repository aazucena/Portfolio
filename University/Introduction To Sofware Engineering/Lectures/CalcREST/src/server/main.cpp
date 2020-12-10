#include <restbed>
#include <nlohmann/json.hpp>
#include <cstring>
#include <cstdlib>
#include <memory>
#include <string>
#include "Calculator.h"

enum OPERATION {ADD, SUB, MULT, DIV, UNKNOWN};

struct expression {
    OPERATION op;
    double first;
    double second;
};

// Response header to prevent a cross-site validation problem
#define ALLOW_ALL { "Access-Control-Allow-Origin", "*" }

// Response header to close connection
#define CLOSE_CONNECTION { "Connection", "close" }

void set_operation(expression* expr, const char* operation) {
    if (strcmp("add", operation) == 0)
        expr->op = ADD;
    else if (strcmp("sub", operation) == 0)
        expr->op = SUB;
    else if (strcmp("mul", operation) == 0)
        expr->op = MULT;
    else if (strcmp("div", operation) == 0)
        expr->op = DIV;
    else
        expr->op = UNKNOWN;
}

/**
 * Parses an expression of the format "<OPERATION>,<double>,<double>"
 * @param data The string to parse.
 * @param exp A pointer to the expression struct to fill in.
 */
void parse(const char* data, expression* expr) {
    char* data_mutable = const_cast<char*>(data);
    char* operation = strtok_r(data_mutable, ",", &data_mutable);
    char* a = strtok_r(nullptr, ",", &data_mutable);
    char* b = strtok_r(nullptr, ",", &data_mutable);

    set_operation(expr, operation);
    expr->first = std::stod((std::string)a);
    expr->second = std::stod((std::string)b);
}

/**
* Replies with either the answer or an error message.
*/
void compute(expression exp,
             const std::shared_ptr<restbed::Session >& session) {
    double result;
    Calculator calc;

    try {
        switch (exp.op) {
        case ADD:
            result = calc.add(exp.first, exp.second);
            break;
        case SUB:
            result = calc.subtract(exp.first, exp.second);
            break;
        case MULT:
            result = calc.multiply(exp.first, exp.second);
            break;
        case DIV:
            result = calc.divide(exp.first, exp.second);;
            break;
        default:
            std::string errorMsg = "Invalid Operator";
            session->close(restbed::BAD_REQUEST, "Invalid Operator", { ALLOW_ALL, { "Content-Length", std::to_string(errorMsg.length()) }, CLOSE_CONNECTION });
            return;
        }
    } catch(div_by_zero_error& ) {
        std::string errorMsg = "Invalid Operator";
        session->close(restbed::BAD_REQUEST, "Division by zero.", { ALLOW_ALL, { "Content-Length", std::to_string(errorMsg.length()) }, CLOSE_CONNECTION });
        return;
    }

    std::string resultStr = std::to_string(result);
    nlohmann::json resultJSON;
    resultJSON["result"] = resultStr;
    std::string response = resultJSON.dump();

    session->close(restbed::OK, response, { ALLOW_ALL, { "Content-Length", std::to_string(response.length()) }, CLOSE_CONNECTION });
}

/**
* POST request callback function.
*/
void post_request(const std::shared_ptr<restbed::Session >&
                  session, const restbed::Bytes & body) {
    expression exp;
    const char* data = reinterpret_cast<const char*>(body.data());
    parse(data, &exp);
    compute(exp, session);
}

/**
* Handle a POST request.
* @param session The request session.
*/
void post_method_handler(const std::shared_ptr<restbed::Session>& session) {
    const auto request = session->get_request();
    size_t content_length = request->get_header("Content-Length", 0);
    session->fetch(content_length, &post_request);
}

/**
* Handle a GET request.
* @param session The request session.
*/
void get_method_handler(const std::shared_ptr<restbed::Session>& session) {
    const auto request = session->get_request();

    expression exp;
    exp.op = UNKNOWN;
    exp.first = 0;
    exp.second = 0;

    if (request->has_query_parameter("op")) {
        set_operation(&exp, request->get_query_parameter("op").c_str());
        if (request->has_query_parameter("first")) {
            exp.first = stod(request->get_query_parameter("first"));
        }
        if (request->has_query_parameter("second")) {
            exp.second = stod(request->get_query_parameter("second"));
        }
    }

    compute(exp, session);
}


int main(const int, const char**) {
    // Setup service and request handlers
    auto resource = std::make_shared<restbed::Resource>();
    resource->set_path("/calc");
    resource->set_method_handler("POST", post_method_handler);
    resource->set_method_handler("GET", get_method_handler);

    auto settings = std::make_shared<restbed::Settings>();
    settings->set_port(1234);

    // Publish and start service
    restbed::Service service;
    service.publish(resource);

    service.start(settings);
    return EXIT_SUCCESS;
}
