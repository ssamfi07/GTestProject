#ifndef HANDLEEMPLOYEES_HPP
#define HANDLEEMPLOYEES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

#include "IEmployee.hpp"
#include "Logger.hpp"
#include "IHandleEmployees.hpp"

class HandleEmployees: public IHandleEmployees
{
    std::vector<std::shared_ptr<IEmployee>> employees_;
public:
    HandleEmployees() = default;
    void addEmployee(std::shared_ptr<IEmployee>) override;
    void displayEmployees() override;
};

void HandleEmployees::addEmployee(std::shared_ptr<IEmployee> employee)
{
    employees_.push_back(employee);
}

void HandleEmployees::displayEmployees()
{
    for(auto employee : employees_)
    {
        employee->display();
    }
}

#endif // HANDLEEMPLOYEES_HPP