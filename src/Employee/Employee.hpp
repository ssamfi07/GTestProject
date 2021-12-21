#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

class Staff
{
    boost::uuids::uuid employeeId_;
    std::string employeeName_;
    float salary_;

public:
    Staff();
    Staff(std::string employeeName, float salary);
    void display();
    void operator =(Staff s1);
};

#endif // EMPLOYEE_HPP