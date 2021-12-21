#include <gtest/gtest.h>
#include "UseEmployee.hpp"

// add stub and mocking

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
    useEmployee_->filepath_ = "/home/sstef/Documents/Faculta/tas/tema/GTestProject/input/in.txt";
    useEmployee_->operateFile();
}

TEST_F(UseEmployeeTest, operateFileFail)
{
    useEmployee_->filepath_ = "./input/in.txt";
    useEmployee_->operateFile();
}

TEST_F(UseEmployeeTest, displayStaff)
{
    useEmployee_->displayStaff();
}

} // namespace gtest
