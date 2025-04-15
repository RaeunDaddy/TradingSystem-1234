#include "gmock/gmock.h"

TEST(Basic, SelectSB) { 
    EXPECT_EQ(true, SbdInterface().selectStockBrocker(stockBrocker));
}

TEST(Basic, Login_Pass) {
    EXPECT_EQ(true, SbdInterface().login(id, password));
}

TEST(Basic, Login_Fail) {
    EXPECT_EQ(false, SbdInterface().login(id, password));   // wrong id
    EXPECT_EQ(false, SbdInterface().login(id, password));   // wrong password
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}