#ifndef USEEMPLOYEES_HPP
#define USEEMPLOYEES_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

#include "Employee.hpp"
#include "Logger.hpp"
#include "HandleEmployees.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>


class UseEmployees
{
    std::shared_ptr<IHandleEmployees> employeeHandler_;
public:
    UseEmployees();
    UseEmployees(const std::shared_ptr<IHandleEmployees>);
    void operateFile();
    void display();

    std::string filepath_;
};

UseEmployees::UseEmployees(const std::shared_ptr<IHandleEmployees> employeeHandler):
filepath_("in.txt"),
employeeHandler_(employeeHandler)
{}

void UseEmployees::operateFile()
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
        employeeHandler_->addEmployee(employee);
    }
    fin.close();
}

void UseEmployees::display()
{
    employeeHandler_->displayEmployees();
}

#endif // USEEMPLOYEE_HPP