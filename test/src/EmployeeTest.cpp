#include <gtest/gtest.h>
#include "Employee.hpp"

// add stub and mocking

namespace gtest 
{

class EmployeeTest : public::testing::Test
{
    protected:
        Staff* employee_;

        virtual ~EmployeeTest(){}

        virtual void SetUp() override
        {
            employee_ = new Staff("Gigi", 5435.54);
        }

        virtual void TearDown()
        {
        }
};

TEST_F(EmployeeTest, display_employee)
{
    employee_->display();
}

TEST_F(EmployeeTest, assign_operator)
{
    Staff employee = *employee_;
    EXPECT_EQ(employee, *employee_);
}

} // namespace gtest
