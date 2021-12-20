#ifndef USE_EMPLOYEE_HPP
#define USE_EMPLOYEE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "../Employee/Employee.hpp"


class UseEmployee : public Staff
{
    int staffSize_;

public:
    UseEmployee();
    void operateFile();
    void displayStaff();
};

UseEmployee::UseEmployee(): staffSize_(0){}

void UseEmployee::operateFile()
{
    std::string fileName("../../input/in.txt");
    std::ifstream fin(fileName);

    if(fin.is_open())
    {
        std::cerr << "Could not open file " << fileName << std::endl;
        return;
    }

    std::string name;
    float salary;
    while(!fin.eof())
    {
        fin >> name >> salary;
        std::cout << name << std::endl << salary << std::endl;
    }

    fin.close();
}

void UseEmployee::displayStaff()
{
    
}

#endif // USE_EMPLOYEE_HPP