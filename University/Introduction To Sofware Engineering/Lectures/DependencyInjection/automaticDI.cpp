#include <iostream>
#include <typeinfo>

#include "Interfaces.h"
#include "DependencyManager.h"

using namespace std;

class SimpleStockTrader : public AutomatedStockTrader
{
public:
    SimpleStockTrader(StockAnalysisService* s, StockBrokerageService* b):
        service{s}, brokerage{b}{};


    void executeTrade()
    {
        for(const string symbol : brokerage->getStockSymbols())
        {
            double askingPrice = brokerage->getAskingPrice(symbol);
            double estimatedValue = service->getEstimatedValue(symbol);
            if(askingPrice < estimatedValue)
                brokerage->putBuyOrder(symbol, 100, askingPrice);
        }
    }

private:
    StockAnalysisService* service;
    StockBrokerageService* brokerage;
};

int main()
{
    AutomatedStockTrader* trader = (AutomatedStockTrader*)DependencyManager::create(&typeid(AutomatedStockTrader));
    trader->executeTrade();
}
