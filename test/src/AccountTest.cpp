#include <gtest/gtest.h>
#include "Account.hpp"

// add stub and mocking

namespace gtest 
{

class AccountTest : public::testing::Test
{
    protected:
        bank::Account* account_;

        virtual ~AccountTest(){}

        virtual void SetUp() override
        {
            account_ = new bank::Account();
            account_ = new bank::Account(200);
        }

        virtual void TearDown()
        {
            delete account_;
        }
};

TEST_F(AccountTest, addDeposit)
{
    account_->Deposit(3.1415);
}

TEST_F(AccountTest, substractDeposit)
{
    account_->Withdraw(3.1415);
}

TEST_F(AccountTest, transferFunds)
{
    account_->TransferFunds(*account_, 3.14);
}

TEST_F(AccountTest, transferMinFunds)
{
    bank::Account newAccount(200);
    account_->TransferMinFunds(newAccount, 3.14);
}

} // namespace gtest
