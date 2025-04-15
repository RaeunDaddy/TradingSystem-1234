#include "MockDriver.h"

void MockDriver::buyStock(const string& stockCode, int buyingPrice,
                          int quantity) {
	cout << "buying stock code " << stockCode << "price :" << buyingPrice << ", quantity = " << quantity << endl;
}
void MockDriver::sellStock(const string& stockCode, int sellingPrice,
                           int quantity) {
	cout << "selling stock code " << stockCode << "price :" << sellingPrice << ", quantity = " << quantity << endl;
}