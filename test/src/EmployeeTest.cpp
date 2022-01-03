#include <gtest/gtest.h>
#include <stdexcept>
#include "Employee.hpp"
#include "MockAccount.hpp"

// add stub and mocking

namespace gtest 
{

class EmployeeTest : public::testing::Test
{
    protected:
        std::shared_ptr<Employee> employee_;
        std::shared_ptr<MockAccount> accountMock_;

        virtual ~EmployeeTest(){}

        virtual void SetUp() override
        {
            accountMock_ = std::make_shared<MockAccount>();
        }

        virtual void TearDown()
        {
        }
};

TEST_F(EmployeeTest, createEmptyEmployee)
{
    employee_ = std::make_shared<Employee>();
    // employee_->display();
}

TEST_F(EmployeeTest, displayEmployee)
{
    employee_ = std::make_shared<Employee>("Gigel", 432.43, accountMock_);
    employee_->display();
}

TEST_F(EmployeeTest, addSalary)
{
    employee_ = std::make_shared<Employee>("Gigel", 432.43, accountMock_);
    EXPECT_CALL(*accountMock_, Deposit(432.43)).Times(1);
    employee_->addSalary();
}

} // namespace gtest
