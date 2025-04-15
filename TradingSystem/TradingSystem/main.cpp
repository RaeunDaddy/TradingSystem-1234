#include "IStockTrader.h"
#include "gmock/gmock.h"

IStockTrader *selectStockerBrocker(const string &driver) {
  if (driver == "Kiwer") return new KiwerDriver();
  if (driver == "Nemo") return new NemoDriver();
  return nullptr;
}

TEST(Basic, SelectSBKiwer) {
  IStockTrader *stockTrader = selectStockerBrocker("Kiwer");
  EXPECT_EQ("Kiwer", stockTrader->getType());
}

// TEST(Basic, Login_Pass) { EXPECT_EQ(true, SbdInterface().login(id,
// password)); }

// TEST(Basic, Login_Fail) {
//   EXPECT_EQ(false, SbdInterface().login(id, password));  // wrong id
//   EXPECT_EQ(false, SbdInterface().login(id, password));  // wrong password
// }

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}