#pragma once

#include "IStockBrockerDriver.h"
#include "nemo_api.cpp"

class NemoDriver : public IStockBrockerDriver {
  void LogIn(const string& id, const string& passwd) override {
    NemoAPI().certification(id, passwd);
  };
  void buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {
    NemoAPI().purchasingStock(stockCode, buyingPrice, quantity);
  };
  void sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {
    NemoAPI().sellingStock(stockCode, sellingPrice, quantity);
  };
  int getStockPrice(const string& stockCode) override { return NemoAPI().getMarketPrice(stockCode, 0); };
  string getType() override { return "Nemo"; }
};
