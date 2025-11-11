#include <gtest/gtest.h>
#include <pthread.h>

extern "C" {
    // Define the global variables that bank.c functions need
    int balance = 1000;
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    
    void deposit(void* tx);
    void withdraw(void* tx);
}

TEST(BankTest, DepositThenWithdrawWithNullTransaction) {
    balance = 1000;
    deposit(nullptr);
    ASSERT_EQ(balance, 1500);
    withdraw(nullptr);
    ASSERT_EQ(balance, 1250);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

