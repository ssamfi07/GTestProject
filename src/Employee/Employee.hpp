#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Staff
{
    int staff_id = 0;
    char name[20] = "";
    float salary = 0.0f;

public:
    Staff();
    void accept();
    void display();
    friend void sort(char nm[], int n, Staff *s);
    void operator =(Staff s1);
};

#endif // EMPLOYEE_HPP