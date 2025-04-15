#include "IStockTrader.h"
#include "gmock/gmock.h"
#include <string>

IStockTrader *selectStockerBrocker(const string &driver) {
  if (driver == "Kiwer") return new KiwerDriver();
  if (driver == "Nemo") return new NemoDriver();
  return nullptr;
}
class SbdInterface : public IStockTrader {

public:
    bool LogIn(const std::string& id, const std::string& pass) override {
        if (id != "admin")
            return false;
        if (pass != "1234")
            return false;
        return true;
    }

};

TEST(Basic, SelectSBKiwer) {
  IStockTrader *stockTrader = selectStockerBrocker("Kiwer");
  EXPECT_EQ("Kiwer", stockTrader->getType());
}

TEST(Basic, Login_Pass) {
    SbdInterface sb;
    string id = "admin";
    string password = "1234";
    EXPECT_EQ(true, sb.LogIn(id, password));  // 

}

TEST(Basic, Login_Fail) {
    SbdInterface sb;
    string id = "aadmin";
    string password = "1234";
    EXPECT_EQ(false, sb.LogIn(id, password));  // wrong id
    EXPECT_EQ(false, sb.LogIn(id, password));  // wrong password
}

TEST(Basic, Buy) {
    std::string stockCode = 0;

    // buy test
    int buyPrice = 100;
    int buyCount = 10;
    EXPECT_EQ(true, SbdInterface().buyStock(stockCode, buyPrice, buyCount));
}

TEST(Basic, Sell) {
    std::string stockCode = 0;

    // sell test
    int sellPrice = 100;
    int sellCount = 5;

    EXPECT_EQ(true, SbdInterface().sellStock(stockCode, sellPrice, sellCount));
}

TEST(Basic, CurrentPrice) {
    std::string stockCode = 0;

    EXPECT_THAT(SbdInterface().getStockPrice(stockCode), Gt(0));
}

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}