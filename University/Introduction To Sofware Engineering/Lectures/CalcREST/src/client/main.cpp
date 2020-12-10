#include <restbed>
#include <nlohmann/json.hpp>
#include <memory>
#include <string>
#include <future>
#include <cstdio>
#include <cstdlib>
#include <iostream>

/* Service information */
const char* HOST = "localhost";
const int PORT = 1234;

/* Server operations */
const char* ADD = "add";
const char* SUBTRACT = "sub";
const char* MULTIPLY = "mul";
const char* DIVIDE = "div";

/**
* Create a POST request for the "calc" service
* @param op The arithmetic operation to request.
* @param a The first number in the computation.
* @param b The second number in the computation.
*/
std::shared_ptr<restbed::Request> create_post_calc_request(const std::string& operation,
        const double a, const double b) {
    // Create the URI string
    std::string uri_str;
    uri_str.append("http://");
    uri_str.append(HOST);
    uri_str.append(":");
    uri_str.append(std::to_string(PORT));
    uri_str.append("/calc");

    // Configure request headers
    auto request = std::make_shared<restbed::Request>(restbed::Uri(uri_str));
    request->set_header("Accept", "*/*");
    request->set_method("POST");
    request->set_header("Content-Type", "text/plain");

    // Create the message
    std::string message;
    message.append(operation);
    message.append(",");
    message.append(std::to_string(a));
    message.append(",");
    message.append(std::to_string(b));

    // Set the message
    request->set_header("Content-Length", std::to_string(message.length()));
    request->set_body(message);

    return request;
}

/**
* Create a GET request for the "calc" service
* @param op The arithmetic operation to request.
* @param a The first number in the computation.
* @param b The second number in the computation.
*/
std::shared_ptr<restbed::Request> create_get_calc_request(const std::string& operation,
        const double a, const double b) {
    // Create the URI string
    std::string uri_str;
    uri_str.append("http://");
    uri_str.append(HOST);
    uri_str.append(":");
    uri_str.append(std::to_string(PORT));
    uri_str.append("/calc");

    // Configure request headers
    auto request = std::make_shared<restbed::Request>(restbed::Uri(uri_str));
    request->set_method("GET");

    // Set the parameters
    request->set_query_parameter("op", operation);
    request->set_query_parameter("first", std::to_string(a));
    request->set_query_parameter("second", std::to_string(b));

    return request;
}

/**
* Handle the response from the service.
* @param response The response object from the server.
*/
void handle_response(std::shared_ptr<restbed::Response> response) {
    int status_code = response->get_status_code();
    auto length = response->get_header("Content-Length", 0);

    switch (status_code) {
    case 200: {
        restbed::Http::fetch(length, response);
        std::string responseStr(reinterpret_cast<char*>(response->get_body().data()), length);

        nlohmann::json resultJSON = nlohmann::json::parse(responseStr);
        std::string result = resultJSON["result"];

        std::cout << "Answer: " << result << std::endl;
        break;
    }
    case 400: {
        restbed::Http::fetch(length, response);
        fprintf(stderr, "Unable to compute: %.*s\n", length,
                 response->get_body().data());
        break;
    }
    default:
        fprintf(stderr,
                 "An error occurred with the service. (Is the service running?)\n");
        break;
    }
}

int main(const int, const char**) {
    // A POST request
    std::shared_ptr<restbed::Request> request = create_post_calc_request(DIVIDE, 120, 5);
    auto response = restbed::Http::sync(request);
    handle_response(response);

    // A GET request
    request = create_get_calc_request(DIVIDE, 15, 3);
    response = restbed::Http::sync(request);
    handle_response(response);

    // A request error - invalid operator
    request = create_get_calc_request("error", 0, 0);
    response = restbed::Http::sync(request);
    handle_response(response);

    // A request error - div by zero
    request = create_get_calc_request(DIVIDE, 1, 0);
    response = restbed::Http::sync(request);
    handle_response(response);

    return EXIT_SUCCESS;
}
