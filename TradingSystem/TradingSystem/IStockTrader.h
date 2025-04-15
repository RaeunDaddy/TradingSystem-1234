#pragma once
#include <string>

using std::string;

#define interface struct

interface IStockTrader {
  virtual bool LogIn(const string& id, const string& passwd) = 0;
  virtual bool buyStock(const string& stockCode, int buyingPrice,
                        int quantity) = 0;
  virtual bool sellStock(const string& stockCode, int sellingPrice,
                         int quantity) = 0;
  virtual void getStockPrice(const string& stockCode) = 0;
  virtual string getType() = 0;
};

class KiwerDriver : public IStockTrader {
  bool LogIn(const string& id, const string& passwd) override {};
  bool buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {};
  bool sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {};
  void getStockPrice(const string& stockCode) override {};
  string getType() override { return "Kiwer"; }
};

class NemoDriver : public IStockTrader {
  bool LogIn(const string& id, const string& passwd) override {};
  bool buyStock(const string& stockCode, int buyingPrice,
                int quantity) override {};
  bool sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override {};
  void getStockPrice(const string& stockCode) override {};
  string getType() override { return "Nemo"; }
};
