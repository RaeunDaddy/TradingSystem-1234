#pragma once

#include "IStockBrockerDriver.h"
#include "kiwer_api.cpp"

class KiwerDriver : public IStockBrockerDriver {
public:
  void LogIn(const string& id, const string& passwd) override {
    KiwerAPI().login(id, passwd);
  };
  void buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {
    KiwerAPI().buy(stockCode, quantity, buyingPrice);
  };
  void sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {
    KiwerAPI().sell(stockCode, quantity, sellingPrice);
  };
  int getStockPrice(const string& stockCode) override {
    return KiwerAPI().currentPrice(stockCode);
  };
  string getType() override { return "Kiwer"; }
};