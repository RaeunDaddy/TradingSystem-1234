#pragma once
#include <string>

using std::string;

class IStockBrockerDriver {
public:
  virtual void LogIn(const string& id, const string& passwd) = 0;
  virtual void buyStock(const string& stockCode, int buyingPrice,
                        int quantity) = 0;
  virtual void sellStock(const string& stockCode, int sellingPrice,
                         int quantity) = 0;
  virtual int getStockPrice(const string& stockCode) = 0;
  virtual string getType() = 0;
};
