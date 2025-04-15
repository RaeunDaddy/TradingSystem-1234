#pragma once
#include "gmock/gmock.h"
#include "IStockBrockerDriver.h"

using std::cout;
using std::endl;

class MockDriver : public IStockBrockerDriver {
 public:
	//MOCK_METHOD(void, buyStock, (const string& stockCode, int buyingPrice, int quantity), (override));
	//MOCK_METHOD(void, sellStock, (const string& stockCode, int sellingPrice, int quantity), (override));
  void LogIn(const string& id, const string& passwd) { }
  void buyStock(const string& stockCode, int buyingPrice,
                int quantity) override;
  void sellStock(const string& stockCode, int sellingPrice,
                 int quantity) override;
    int getStockPrice(const string& stockCode) override {}
	string getType() { return "Mock"; }
};

