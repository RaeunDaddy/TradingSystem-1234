#pragma once
#include "gmock/gmock.h"
#include "IStockTrader.h"

using std::cout;
using std::endl;

class MockStockTrader : public IStockTrader {
public:
	//MOCK_METHOD(void, buyStock, (const string& stockCode, int buyingPrice, int quantity), (override));
	//MOCK_METHOD(void, sellStock, (const string& stockCode, int sellingPrice, int quantity), (override));
	bool LogIn(const string& id, const string& passwd) { return true; }
	bool buyStock(const string& stockCode, int buyingPrice, int quantity) override;
	bool sellStock(const string& stockCode, int sellingPrice, int quantity) override;
	void getStockPrice(const string& stockCode) override {}
	string getType() { return "Mock"; }
};

