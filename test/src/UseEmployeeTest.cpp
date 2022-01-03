#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "UseEmployee.hpp"
#include "MockEmployee.hpp"

// add stub and mocking

using ::testing::AtLeast;
using ::testing::_;

namespace gtest 
{

class UseEmployeeTest : public::testing::Test
{
    protected:
        std::shared_ptr<UseEmployee> useEmployee_;
        std::shared_ptr<MockEmployee> mockEmployee_;
        virtual ~UseEmployeeTest(){}

        virtual void SetUp() override
        {
            useEmployee_ = std::make_shared<UseEmployee>();
            mockEmployee_ = std::make_shared<MockEmployee>();
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
    useEmployee_->filepath_ = "/home/sstef/Documents/Faculta/tas/tema/GTestProject/input/in.txt";
    useEmployee_->operateFile();
    useEmployee_->displayEmployees();
}

} // namespace gtest
