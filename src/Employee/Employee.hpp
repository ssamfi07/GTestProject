#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string.h>
#include <functional>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "IEmployee.hpp"
#include "Account.hpp"

class Employee: public IEmployee
{
    boost::uuids::uuid employeeId_;
    std::string employeeName_;
    float salary_;
    std::shared_ptr<bank::IAccount> account_;
public:
    Employee();
    Employee(std::string employeeName, float salary, std::shared_ptr<bank::IAccount> account);
    void display() override;
    void addSalary() override;
};

#endif // EMPLOYEE_HPP