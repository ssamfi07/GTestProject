#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "UseEmployees.hpp"
#include "MockEmployeesHandler.hpp"

namespace gtest
{

class UseEmployeesTest : public::testing::Test
{
    protected:
        std::shared_ptr<UseEmployees> useEmployees_;
        std::shared_ptr<MockEmployeeHandler> employeeHandlerMock_;
        virtual ~UseEmployeesTest(){}

        virtual void SetUp() override
        {
            employeeHandlerMock_ = std::make_shared<MockEmployeeHandler>();
            useEmployees_ = std::make_shared<UseEmployees>(employeeHandlerMock_);
        }

        virtual void TearDown()
        {
        }
};

TEST_F(UseEmployeesTest, operateFile)
{
    EXPECT_NE(useEmployees_, nullptr);
    useEmployees_->filepath_ = "/home/sstef/Documents/Faculta/tas/tema/GTestProject/input/in.txt";
    EXPECT_CALL(*employeeHandlerMock_, addEmployee).Times(::testing::AtLeast(1));
    useEmployees_->operateFile();
}

TEST_F(UseEmployeesTest, operateFileFail)
{
    EXPECT_NE(useEmployees_, nullptr);
    useEmployees_->filepath_ = "./input/in.txt";
    useEmployees_->operateFile();
}

TEST_F(UseEmployeesTest, display)
{
    EXPECT_NE(useEmployees_, nullptr);
    EXPECT_CALL(*employeeHandlerMock_, displayEmployees).Times(::testing::AtLeast(1));
    useEmployees_->display();
}

} // namespace gtest
