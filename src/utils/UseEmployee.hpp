#ifndef USE_EMPLOYEE_HPP
#define USE_EMPLOYEE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

#include "Employee.hpp"
#include "Logger.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>


class UseEmployee : public Staff
{
    int staffSize_;
    std::vector<Staff> employees_;
public:
    UseEmployee();
    void operateFile();
    void displayStaff();

    std::string filepath_;
};

UseEmployee::UseEmployee(): 
staffSize_(0),
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
    while(!fin.eof())
    {
        // read employee info and add to vector
        fin >> name >> salary;
        employees_.push_back(Staff(name, salary));
    }

    staffSize_ = employees_.size();

    fin.close();
}

void UseEmployee::displayStaff()
{
    std::for_each(employees_.begin(), employees_.end(), std::bind(&Staff::display, this));
}

#endif // USE_EMPLOYEE_HPP