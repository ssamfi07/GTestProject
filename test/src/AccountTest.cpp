#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdexcept>
#include "Account.hpp"
#include "MockAccount.hpp"

// add stub and mocking

namespace gtest 
{

class AccountTest : public::testing::Test
{
    protected:
        bank::Account* account_;
        std::shared_ptr<MockAccount> accountMock_ = std::make_shared<MockAccount>();

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
    EXPECT_NE(account_, nullptr);
    account_->Deposit(3.1415);
}

TEST_F(AccountTest, substractDeposit)
{
    EXPECT_NE(account_, nullptr);
    account_->Withdraw(3.1415);
}

TEST_F(AccountTest, transferFunds)
{
    EXPECT_NE(account_, nullptr);
    // EXPECT_CALL(*accountMock_, Withdraw(::testing::_)).Times(1);
    account_->TransferFunds(*account_, 3.14);
}

TEST_F(AccountTest, transferMinFundsPass)
{
    EXPECT_NE(account_, nullptr);
    try
    {
        bank::Account newAccount(200);
        // EXPECT_NE(newAccount, nullptr);
        account_->TransferMinFunds(newAccount, 3.14);
    }
    catch(std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("Not Enough Funds"));
    }
}

TEST_F(AccountTest, transferMinFundsFails)
{
    EXPECT_NE(account_, nullptr);
    account_->Withdraw(190);
    try
    {
        bank::Account newAccount(200);
        // EXPECT_NE(newAccount, nullptr);
        account_->TransferMinFunds(newAccount, 3.14);
    }
    catch(std::out_of_range const& e)
    {
        EXPECT_EQ(e.what(), std::string("Not Enough Funds"));
    }
    catch(...)
    {
        FAIL() << "Expected std::out_of_range";
    }
}

} // namespace gtest
