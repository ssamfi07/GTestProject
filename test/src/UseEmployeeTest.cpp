#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "UseEmployee.hpp"

namespace gtest 
{

class UseEmployeeTest : public::testing::Test
{
    protected:
        std::shared_ptr<UseEmployee> useEmployee_;
        virtual ~UseEmployeeTest(){}

        virtual void SetUp() override
        {
            useEmployee_ = std::make_shared<UseEmployee>();
        }

        virtual void TearDown()
        {
        }
};

TEST_F(UseEmployeeTest, operateFile)
{
    EXPECT_NE(useEmployee_, nullptr);
    useEmployee_->filepath_ = "/home/sstef/Documents/Faculta/tas/tema/GTestProject/input/in.txt";
    useEmployee_->operateFile();
}

TEST_F(UseEmployeeTest, operateFileFail)
{
    EXPECT_NE(useEmployee_, nullptr);
    useEmployee_->filepath_ = "./input/in.txt";
    useEmployee_->operateFile();
}

TEST_F(UseEmployeeTest, displayStaff)
{
    EXPECT_NE(useEmployee_, nullptr);
    useEmployee_->filepath_ = "/home/sstef/Documents/Faculta/tas/tema/GTestProject/input/in.txt";
    useEmployee_->operateFile();
    useEmployee_->displayEmployees();
}

} // namespace gtest
