#pragma once
#include <string>

using std::string;

#define interface struct

interface IStockTrader {
  virtual void LogIn(const string& id, const string& passwd) = 0;
  virtual void buyStock(const string& stockCode, int buyingPrice,
                        int quantity) = 0;
  virtual void sellStock(const string& stockCode, int sellingPrice,
                         int quantity) = 0;
  virtual void getStockPrice(const string& stockCode) = 0;
  virtual string getType() = 0;
};

class KiwerDriver : public IStockTrader {
  void LogIn(const string& id, const string& passwd) override {};
  void buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {};
  void sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {};
  void getStockPrice(const string& stockCode) override {};
  string getType() override { return "Kiwer"; }
};

class NemoDriver : public IStockTrader {
  void LogIn(const string& id, const string& passwd) override {};
  void buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {};
  void sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {};
  void getStockPrice(const string& stockCode) override {};
  string getType() override { return "Nemo"; }
};