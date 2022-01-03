#ifndef IHANDLEEMPLOYEES_HPP
#define IHANDLEEMPLOYEES_HPP

#include <memory>
#include "Employee.hpp"

class IHandleEmployees
{
public:
    IHandleEmployees(){}
    virtual ~IHandleEmployees() = default;
    virtual void addEmployee(std::shared_ptr<IEmployee>) = 0;
    virtual void displayEmployees() = 0;
};

#endif // IHANDLEEMPLOYEES_HPP