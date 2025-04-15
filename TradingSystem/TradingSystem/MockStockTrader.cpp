#include "MockStockTrader.h"

bool MockStockTrader::buyStock(const string& stockCode, int buyingPrice, int quantity) {
	cout << "buying stock code " << stockCode << "price :" << buyingPrice << ", quantity = " << quantity << endl;
	return true;
}
bool MockStockTrader::sellStock(const string& stockCode, int sellingPrice, int quantity) {
	cout << "selling stock code " << stockCode << "price :" << sellingPrice << ", quantity = " << quantity << endl;
	return true;
}