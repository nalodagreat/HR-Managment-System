#pragma once
#include "Employee.h"
#include <string>
#include <vector>

using namespace std;

/*
 * Concrete Class: Executive
 * Inherits from the abstract Employee class.
*/
class Executive : public Employee {
private:
    string divisionName;

public:
    Executive(const string& tc, const string& fn, const string& ln, const string& hd, const string& divName)
        : Employee(tc, fn, ln, hd), divisionName(divName) {}

    double calculateSalary(const vector<Employee*>& allEmployees) override {
        double baseSalary = 2500.0;
        double bonusPool = 0.0;

        // Iterate through all employees to sum up their salaries for the bonus pool.
        for (Employee* emp : allEmployees) {
            
            // Safely check if the employee is an Executive.
            Executive* exec = dynamic_cast<Executive*>(emp);
            if (exec == nullptr) { // If the dynamic_cast fails, emp is NOT an Executive.
                bonusPool += emp->calculateSalary(allEmployees);
            }
        }

        return baseSalary + (0.10 * bonusPool);
    }

    string getDivisionName() const { return divisionName; }
};