#ifndef AUTOMATEDSTOCKTRADER_H_INCLUDED
#define AUTOMATEDSTOCKTRADER_H_INCLUDED

#include <vector>

using namespace std;


class AutomatedStockTrader
{
public:
    virtual void executeTrade() = 0;
};

class StockAnalysisService
{
public:
    virtual double getEstimatedValue(const string symbol) const = 0;
};

class StockBrokerageService
{
public:
    virtual vector<string> getStockSymbols() = 0;
    virtual double getAskingPrice(const string symbol) const = 0;
    virtual void putBuyOrder(const string symbol, unsigned int amount, const double price) = 0;
};

class AwesomeStockAnalysisService : public StockAnalysisService
{
public:
    double getEstimatedValue(const string symbol) const {return 0.0;}
};

class NYStockExchangeBrokerage : public StockBrokerageService
{
public:
    vector<string> getStockSymbols() { return vector<string>();};
    double getAskingPrice(const string symbol) const {return 0.0;}
    void putBuyOrder(const string symbol, unsigned int amount, const double price) {}
};


#endif // AUTOMATEDSTOCKTRADER_H_INCLUDED
