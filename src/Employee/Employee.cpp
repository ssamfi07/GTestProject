#include <iostream>
#include <string.h>
#include <fstream>
#include "Employee.hpp"

Staff::Staff() {}

void Staff::operator =(Staff s1)
{
    staff_id = s1.staff_id;
    strcpy(name, s1.name);
    salary = s1.salary;
}

void Staff::display()
{
    std::cout << "\n Staff Id : " << Staff::staff_id;
    std::cout << "\n Name : " << Staff::name;
    std::cout << "\n Salary : " << Staff::salary << "\n";
}
void sort(char nm[], int n, Staff *s) // Function for sorting the data by employee name
{
    Staff temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int r = strcmp(s[i].name, s[j].name);
            if (r > 0)
            {
                temp = *(s + i);
                *(s + i) = *(s + j);
                *(s + j) = temp;
            }
        }
    }
}
