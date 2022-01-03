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
    EXPECT_EQ(nullptr, employee_);
    employee_ = std::make_shared<Employee>();
    EXPECT_NE(employee_, nullptr);
}

TEST_F(EmployeeTest, displayEmployee)
{
    EXPECT_EQ(nullptr, employee_);
    employee_ = std::make_shared<Employee>("Gigel", 432.43, accountMock_);
    EXPECT_NE(employee_, nullptr);
    employee_->display();
}

TEST_F(EmployeeTest, addSalary)
{
    EXPECT_EQ(nullptr, employee_);
    employee_ = std::make_shared<Employee>("Gigel", 432.43, accountMock_);
    EXPECT_NE(employee_, nullptr);
    EXPECT_CALL(*accountMock_, Deposit(432.43)).Times(1);
    employee_->addSalary();
}

TEST_F(EmployeeTest, substractTaxes)
{
    EXPECT_EQ(nullptr, employee_);
    employee_ = std::make_shared<Employee>("Gigel", 432.43, accountMock_);
    EXPECT_NE(employee_, nullptr);
    EXPECT_CALL(*accountMock_, Withdraw(43.243)).Times(1);
    employee_->substractTaxes();
}

} // namespace gtest
