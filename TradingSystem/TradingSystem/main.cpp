#include "IStockBrockerDriver.h"
#include "MockDriver.h"
#include "KiwerDriver.h"
#include "NemoDriver.h"

#include "StockBrockerInterface.h"

#include "gmock/gmock.h"

#include <string>

TEST(Basic, SelectSBKiwer) {
    StockBrockerInterface *stockBrockerInterface = new StockBrockerInterface();
    IStockBrockerDriver *stockTrader =
        stockBrockerInterface->selectStockerBrocker("Kiwer");
    EXPECT_EQ("Kiwer", stockTrader->getType());
}

TEST(Basic, Login_Pass) {
  StockBrockerInterface *stockBrockerInterface = new StockBrockerInterface();
  IStockBrockerDriver *stockTrader =
      stockBrockerInterface->selectStockerBrocker("Kiwer");
    string id = "admin";
    string password = "1234";
    EXPECT_EQ(true, stockBrockerInterface->LogIn(id, password));  // 

}

TEST(Basic, Buy) {
  StockBrockerInterface *stockBrockerInterface = new StockBrockerInterface();
  IStockBrockerDriver *stockTrader =
      stockBrockerInterface->selectStockerBrocker("Kiwer");
    std::string stockCode = "Samsung";

    // buy test
    int buyPrice = 100;
    int buyCount = 10;
    EXPECT_EQ(true,
              stockBrockerInterface->buyStock(stockCode, buyPrice, buyCount));
}

TEST(Basic, Sell) {
  StockBrockerInterface *stockBrockerInterface = new StockBrockerInterface();
  IStockBrockerDriver *stockTrader =
      stockBrockerInterface->selectStockerBrocker("Kiwer");
    std::string stockCode = "Samsung";

    // sell test
    int sellPrice = 100;
    int sellCount = 5;

    EXPECT_EQ(true, stockBrockerInterface->sellStock(stockCode, sellPrice,
                                                      sellCount));
}

TEST(Basic, CurrentPrice) {
  StockBrockerInterface *stockBrockerInterface = new StockBrockerInterface();
  IStockBrockerDriver *stockTrader =
      stockBrockerInterface->selectStockerBrocker("Kiwer");
    std::string stockCode = "Samsung";

    EXPECT_GE(stockBrockerInterface->getStockPrice(stockCode), 0);
}

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}