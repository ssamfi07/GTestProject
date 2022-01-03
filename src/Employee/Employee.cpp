#include <memory>

#include "Employee.hpp"
#include "Logger.hpp"

Employee::Employee(): 
employeeId_(boost::uuids::random_generator()()),
employeeName_(""),
salary_(0.0f)
{}

Employee::Employee(std::string employeeName, float salary, std::shared_ptr<bank::IAccount> account):
employeeId_(boost::uuids::random_generator()()),
employeeName_(employeeName),
salary_(salary),
account_(account)
{
}

void Employee::display()
{
    LOG_INFO << "EmployeeId: " << Employee::employeeId_ << "\tName: " << Employee::employeeName_ 
            << "\tSalary: " << Employee::salary_;
}

void Employee::addSalary()
{
    account_->Deposit(salary_);
}

void Employee::substractTaxes()
{
    // withdraws 10% of the salary as taxes
    account_->Withdraw(salary_ / 10.0f);
}
