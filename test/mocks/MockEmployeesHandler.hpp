#ifndef MOCKEMPLOYEEHANDLER_HPP
#define MOCKEMPLOYEEHANDLER_HPP

#include "gmock/gmock.h"
#include "IHandleEmployees.hpp"

// add stub and mocking

namespace gtest 
{

class MockEmployeeHandler : public IHandleEmployees
{
    public:
        MOCK_METHOD(void, addEmployee, (std::shared_ptr<IEmployee>), (override));
        MOCK_METHOD(void, displayEmployees, (), (override));
};

} // namespace gtest
#endif // MOCKEMPLOYEEHANDLER_HPP