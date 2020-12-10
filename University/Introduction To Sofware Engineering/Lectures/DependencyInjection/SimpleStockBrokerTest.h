#ifndef SIMPLESTOCKBROKERTEST_H_INCLUDED
#define SIMPLESTOCKBROKERTEST_H_INCLUDED

#include "DependencyManager.h"
#include <typeinfo>

using namespace std;

class StockAnalysisService_Stub : public StockAnalysisService
{
public:
    double getEstimatedValue(const string symbol) const
    {
        if(strcmp("GGL",symbol) == 0)
            return 50.0;
        return 25.0;
    }
};

class BrokerageService_Stub : public StockBrokerageService
{
public:
    vector<string> getStockSymbols()
    {
        vector<string> symbols;
        symbols.push_back("AMZ");
        symbols.push_back("GGL");
        symbols.push_back("MST");
        return symbols;
    };
    double getAskingPrice(const string symbol) const
    {
        return 10.0;
    }
    void putBuyOrder(const string symbol, unsigned int amount, const double price)
    {
        cout << "Ordered: " << symbol << " - " << price << endl;
    }
};

TEST (StockTest, executeTrade)
{
    DependencyManager::register(&typeid(StockAnalysisService), &typeid(StockAnalysisService_Stub));
    DependencyManager::register(&typeid(StockBrokerageService), &typeid(BrokerageService_Stub));

    AutomatedStockTrader* trader =
        (AutomatedStockTrader*)DependencyManager::create(&typeid(AutomatedStockTrader));
    trader->executeTrade();

}

#endif // SIMPLESTOCKBROKERTEST_H_INCLUDED
