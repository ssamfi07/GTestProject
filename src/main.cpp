#include <iostream>
#include <memory>
#include "./utils/UseEmployee.hpp"
#include "./logger/Logger.hpp"

int main(int argc, char* argv[])
{
    LOG_INFO << "Starting program...";
    UseEmployee employees = UseEmployee();
    return 0;
}
