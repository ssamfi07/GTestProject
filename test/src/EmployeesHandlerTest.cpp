#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "HandleEmployees.hpp"
#include "MockEmployee.hpp"

namespace gtest
{

class HandleEmployeesTest : public::testing::Test
{
    protected:
        std::shared_ptr<HandleEmployees> handleEmployees_;
        std::shared_ptr<MockEmployee> mockEmployee_;
        virtual ~HandleEmployeesTest(){}

        virtual void SetUp() override
        {
            mockEmployee_ = std::make_shared<MockEmployee>();
            handleEmployees_ = std::make_shared<HandleEmployees>();
        }

        virtual void TearDown()
        {
        }
};

TEST_F(HandleEmployeesTest, addEmployee)
{
    EXPECT_NE(handleEmployees_, nullptr);
    handleEmployees_->addEmployee(nullptr);
}

TEST_F(HandleEmployeesTest, display)
{
    EXPECT_NE(handleEmployees_, nullptr);
    // EXPECT_CALL(*mockEmployee_, display).Times(::testing::AtLeast(1));
    handleEmployees_->displayEmployees();
}

} // namespace gtest
