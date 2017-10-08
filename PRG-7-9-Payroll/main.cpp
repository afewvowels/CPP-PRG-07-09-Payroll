//
//  main.cpp
//  PRG-7-9-Payroll
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that uses the following arrays:
//
//  * empId: an array of seven long integers to hold employee identification numbers. The
//    array should be initialized with the following numbers:
//    5658845   4520125   7895122   8777541
//    8451277   1302850   7580489
//  * hours: an array of seven integers to hold the number of hours worked by each
//    employee.
//  * payRate: an array of seven doubles to hold each employee's hourly pay rate
//  * wages: an array of seven doubles to hold each employee's gross wages
//
//  The program shuld relate the data in each array through the subscripts. For example,
//  the number in element 0 of the hours array should be the number of hours worked by
//  the employee whose identification number is stored in element 0 or the empId array.
//  That same employee's pay rate should be stored in element 0 of the payRate array.
//
//  The program should display each employee number and ask the user to enter that
//  employee's hours and pay rate. It should then calculate the gross wages for that employee
//  (hours times pay rate) and store them in the wages array. After the data has been entered
//  for all the employees, the program should display each employee's identification number
//  and gross wages.
//
//  Input Validation: Do not accept negative values for hours or numbers less that 15.00
//  for pay rate.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int INT_EMPLOYEES = 7;

void hoursAndPayRate(const int, const int[], int[], float[]);
void calculateTotalPay(const int, const int[], const int[], const float[], float[]);
void returnWages(const int, const int[], const float[]);

int main()
{
    string strQuit;
    
    const int intEmployeeID[INT_EMPLOYEES] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489 };
    
    int intHours[INT_EMPLOYEES];
    float fltPayRate[INT_EMPLOYEES];
    float fltWages[INT_EMPLOYEES];
    
    hoursAndPayRate(INT_EMPLOYEES, intEmployeeID, intHours, fltPayRate);
    
    calculateTotalPay(INT_EMPLOYEES, intEmployeeID, intHours, fltPayRate, fltWages);
    
    returnWages(INT_EMPLOYEES, intEmployeeID, fltWages);
    
    do
    {
        cout << "Enter exit to quit:\n";
        cin >> strQuit;
    } while (strQuit != "exit");
    
    return 0;
}

void hoursAndPayRate(const int INT_EMPLOYEES, const int intEmployees[], int intHours[], float fltPayRate[])
{
    int intTempHours;
    float fltTempPayrate;
    
    for (int employee = 0; employee < INT_EMPLOYEES; employee++)
    {
        cout << "Please enter the number of hours worked by employee ID " << intEmployees[employee] << ": ";
        cin >> intTempHours;
        while (!cin || intTempHours < 0 || intTempHours > 50)
        {
            cout << "Please enter a number between 0 and 50:\n";
            cin.clear();
            cin.ignore();
            cin >> intTempHours;
        }
        
        intHours[employee] = intTempHours;
        
        cout << "Please enter the payrate for employee ID " << intEmployees[employee] << ": $";
        cin >> fltTempPayrate;
        while (!cin || fltTempPayrate < 15.0f || fltTempPayrate > 150.0f)
        {
            cout << "Please enter a number between $15.00 and $150.00:\n";
            cin.clear();
            cin.ignore();
            cin >> fltTempPayrate;
        }
        
        fltPayRate[employee] = fltTempPayrate;
    }
}

void calculateTotalPay(const int INT_EMPLOYEES, const int intEmployees[], const int intHours[], const float fltPayRate[], float fltWages[])
{
    for (int employee = 0; employee < INT_EMPLOYEES; employee++)
    {
        fltWages[employee] = intHours[employee] * fltPayRate[employee];
    }
}

void returnWages(const int INT_EMPLOYEES, const int intEmployees[], const float fltWages[])
{
    cout << setprecision(2) << fixed << showpoint;
    
    for (int employee = 0; employee < INT_EMPLOYEES; employee++)
    {
        cout << "Employee ID " << intEmployees[employee] << " earned $" << fltWages[employee] << endl;
    }
}

