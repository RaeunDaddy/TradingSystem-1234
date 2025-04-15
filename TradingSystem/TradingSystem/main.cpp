#include "IStockTrader.h"
#include "gmock/gmock.h"
#include <string>

IStockTrader *selectStockerBrocker(const string &driver) {
  if (driver == "Kiwer") return new KiwerDriver();
  if (driver == "Nemo") return new NemoDriver();
  return nullptr;
}

TEST(Basic, SelectSBKiwer) {
  IStockTrader *stockTrader = selectStockerBrocker("Kiwer");
  EXPECT_EQ("Kiwer", stockTrader->getType());
}

TEST(Basic, Login_Pass) {
    EXPECT_EQ(true, SbdInterface().LogIn(id, password));
}

TEST(Basic, Login_Fail) {
    EXPECT_EQ(false, SbdInterface().LogIn(id, password));  // wrong id
    EXPECT_EQ(false, SbdInterface().LogIn(id, password));  // wrong password
}

TEST(Basic, BuySell) {
    std::string stockCode = 0;

    // buy test
    int buyPrice = 100;
    int buyCount = 10;
    EXPECT_EQ(true, SbdInterface().buyStock(stockCode, buyPrice, buyCount));

    EXPECT_EQ(buyCount, SbdInterface().getStockCount(stockCode));

    // sell test
    int sellPrice = 100;
    int sellCount = 5;

    EXPECT_EQ(true, SbdInterface().sellStock(stockCode, sellPrice, sellCount));

    EXPECT_EQ((buyCount - sellCount), SbdInterface().getStockCount(stockCode));
}

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}