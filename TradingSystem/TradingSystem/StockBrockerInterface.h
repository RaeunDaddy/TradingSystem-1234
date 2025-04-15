#pragma once

#include "IStockBrockerDriver.h"
#include "KiwerDriver.h"
#include "NemoDriver.h"

class StockBrockerInterface {
public:
    IStockBrockerDriver *selectStockerBrocker(const string &driver) {
        if (driver == "Kiwer") {
            currentStockBrocker = new KiwerDriver();
        } else if (driver == "Nemo") {
            currentStockBrocker = new NemoDriver();
        } else {
          currentStockBrocker = nullptr;
        }

        return currentStockBrocker;
    }

    bool LogIn(const string& id, const string& passwd) {
        currentStockBrocker->LogIn(id, passwd);

        return true;
    }
    virtual bool buyStock(const string& stockCode, int buyingPrice,
        int quantity) {
        currentStockBrocker->buyStock(stockCode, buyingPrice, quantity);

        return true;
    }
    virtual bool sellStock(const string& stockCode, int sellingPrice, int quantity) {
        currentStockBrocker->sellStock(stockCode, sellingPrice, quantity);

        return true;
    }
    virtual int getStockPrice(const string& stockCode) {
        return currentStockBrocker->getStockPrice(stockCode);
    }

private:
  IStockBrockerDriver* currentStockBrocker;
};
