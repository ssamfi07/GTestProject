#ifndef USEEMPLOYEE_HPP
#define USEEMPLOYEE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

#include "Employee.hpp"
#include "Logger.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>


class UseEmployee
{
    int EmployeeSize_;
    std::vector<std::shared_ptr<Employee>> employees_;
public:
    UseEmployee();
    void operateFile();
    void displayEmployees();

    std::string filepath_;
};

UseEmployee::UseEmployee(): 
EmployeeSize_(0),
filepath_("in.txt")
{}

void UseEmployee::operateFile()
{
    std::string fileName(filepath_);
    std::ifstream fin(fileName);

    if(!fin.is_open())
    {
        LOG_ERROR << "Couldn't open file " << fileName;
        return;
    }

    // file is open here
    std::string name;
    float salary;
    float balance;
    while(!fin.eof())
    {
        // read employee info and add to vector
        fin >> name >> salary >> balance;
        // create account
        std::shared_ptr<bank::Account> account_ = std::make_shared<bank::Account>(balance);
        // create employee
        std::shared_ptr<Employee> employee = std::make_shared<Employee>(name, salary, account_);
        // add salary to initial balance
        employee->addSalary();
        // push employee to vector
        employees_.push_back(employee);
    }

    EmployeeSize_ = employees_.size();

    fin.close();
}

void UseEmployee::displayEmployees()
{
    for(auto employee : employees_)
    {
        employee->display();
    }
}

#endif // USEEMPLOYEE_HPP