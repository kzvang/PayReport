

//Pay Report
//Assignment 4
// Ka Zoua Vang

#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

Employee* GetEmployeeInfo(int i)
{
    Employee* pE = new Employee;
    cout << "Enter the ID for Employee " << i + 1 << ": ";
    cin >> pE->ID;
    cout << "Enter the First Name for Employee " << i + 1 << ": ";
    cin >> pE->FirstName;
    cout << "Enter the Last Name for Employee " << i + 1 << ": ";
    cin >> pE->LastName;
    cout << "Enter the Hours Worked for Employee " << i + 1 << ": ";
    cin >> pE->HoursWorked;
    cout << "Enter the Hourly Rate for Employee " << i + 1 << ": ";
    cin >> pE->HourlyRate;
    return pE;
}

void PrintWeeklyPay(Employee* pEmployees, int size)
{
    cout << "Pay Report \n";
    cout << "------------ \n";

    for (int i = 0; i < size; i++) {

        cout << pEmployees[i].ID << ". " << pEmployees[i].FirstName << " " 
            << pEmployees[i].LastName << ": $" << pEmployees[i].HoursWorked * pEmployees[i].HourlyRate << "\n";

    }

    
}

void PrintTotalPay(Employee* pEmployees, int size)
{
    int Total = 0;

    for (int i = 0; i < size; i++) {

        Total += (pEmployees[i].HourlyRate * pEmployees[i].HoursWorked);
    }

    cout << "\nTotal Pay: $" << Total;
}

int main()
{
    cout << "Enter the number of employees: ";
    int size = 0;
    cin >> size;
    cout << "\n";

    Employee* employees = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        employees[i] = *GetEmployeeInfo(i);
        cout << "\n";
    }

    PrintWeeklyPay(employees, size);
    PrintTotalPay(employees, size);

    delete[] employees;

    (void)_getch();
    return 0;
}