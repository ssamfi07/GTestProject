#ifndef IEMPLOYEE_HPP
#define IEMPLOYEE_HPP

#include <iostream>
#include <memory>
#include <string.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "Account.hpp"

class IEmployee
{
public:
    IEmployee(){}
    virtual ~IEmployee() = default;
    virtual void display() = 0;
    virtual void addSalary() = 0;
    virtual void substractTaxes() = 0;
};

#endif // IEMPLOYEE_HPP