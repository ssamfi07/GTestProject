#include "Employee.hpp"

Staff::Staff(): 
employeeId_(boost::uuids::random_generator()()),
employeeName_(""),
salary_(0.0f)
{}

Staff::Staff(std::string employeeName, float salary):
employeeId_(boost::uuids::random_generator()()),
employeeName_(employeeName),
salary_(salary)
{
}

void Staff::operator =(Staff s1)
{
    employeeId_ = s1.employeeId_;
    employeeName_ = s1.employeeName_;
    salary_ = s1.salary_;
}

void Staff::display()
{
    std::cout << "\n Employee Id : " << Staff::employeeId_;
    std::cout << "\n Name : " << Staff::employeeName_;
    std::cout << "\n Salary : " << Staff::salary_ << "\n";
}
