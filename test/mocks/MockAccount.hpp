#ifndef MOCKACCOUNT_HPP
#define MOCKACCOUNT_HPP

#include "gmock/gmock.h"
#include "IAccount.hpp"

// add stub and mocking

namespace gtest 
{

class MockAccount : public bank::IAccount
{
    public:
        MOCK_METHOD(void, Deposit, (float), (override));
        MOCK_METHOD(void, Withdraw, (float), (override));
};

} // namespace gtest
#endif // MOCKACCOUNT_HPP