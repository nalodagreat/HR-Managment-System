#pragma once
#include <string>
using namespace std;

/*
abstract class Employee
*/
class Employee {
protected:
    
    string taxCode;
    string firstName;
    string lastName;
    string hireDate;

public:
    
    Employee(const string& tc, const string& fn, const string& ln, const string& hd) {
        taxCode = tc;
        firstName = fn;
        lastName = ln;
        hireDate = hd;
    }
    virtual ~Employee() {}
    virtual double calculateSalary() = 0;
    string getTaxCode() const { return taxCode; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getHireDate() const { return hireDate; }
};