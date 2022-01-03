#ifndef MOCKEMPLOYEE_HPP
#define MOCKEMPLOYEE_HPP

#include "gmock/gmock.h"
#include "IEmployee.hpp"

// add stub and mocking

namespace gtest 
{

class MockEmployee : public IEmployee
{
    public:
        MOCK_METHOD(void, display, (), (override));
        MOCK_METHOD(void, addSalary, (), (override));
};

} // namespace gtest
#endif // MOCKEMPLOYEE_HPP
