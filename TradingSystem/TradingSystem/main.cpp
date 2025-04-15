#include "IStockTrader.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>
#include <string>

using namespace testing;
// 🔹 SbdInterface 정의
class SbdInterface
{
public:
    SbdInterface(const std::string &brokerName)
    {
        if (brokerName == "kiwer")
            trader_ = std::make_unique<KiwerDriver>();
        else if (brokerName == "nemo")
            trader_ = std::make_unique<NemoDriver>();
        else
            throw std::runtime_error("Unknown broker name!");
    }

    int getStockPrice(const std::string &stockCode)
    {
        return trader_->getStockPrice(stockCode);
    }

    bool LogIn(const std::string &id, const std::string &passwd)
    {
        trader_->LogIn(id, passwd);
        return true; // 항상 성공 처리 (예시)
    }

private:
    std::unique_ptr<IStockTrader> trader_;
};

IStockTrader *selectStockerBrocker(const string &driver)
{
    if (driver == "Kiwer")
        return new KiwerDriver();
    if (driver == "Nemo")
        return new NemoDriver();
    return nullptr;
}

TEST(Basic, SelectSBKiwer)
{
    IStockTrader *stockTrader = selectStockerBrocker("Kiwer");
    EXPECT_EQ("Kiwer", stockTrader->getType());
}

TEST(Basic, Login_Pass)
{
    EXPECT_EQ(true, SbdInterface().LogIn(id, password));
}

TEST(Basic, Login_Fail)
{
    EXPECT_EQ(false, SbdInterface().LogIn(id, password)); // wrong id
    EXPECT_EQ(false, SbdInterface().LogIn(id, password)); // wrong password
}

TEST(Basic, BuySell)
{
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

TEST(Basic, CurrentPrice)
{
    std::string stockCode = "005930";
    SbdInterface sbd("kiwer");
    EXPECT_THAT(sbd.getStockPrice(stockCode), Gt(0));
}

int main()
{
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}