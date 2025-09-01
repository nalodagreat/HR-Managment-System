#pragma once
#include "Employee.h"
#include "Technician.h"
#include <string>
#include <vector>

using namespace std;

class Manager : public Employee 
{
private:
    string responsibilityField;

public:
    Manager(const string& tc, const string& fn, const string& ln, const string& hd, const string& respField)
        : Employee(tc, fn, ln, hd), responsibilityField(respField) {}

    double calculateSalary(const vector<Employee*>& allEmployees) override {
        double baseSalary = 2000.0;
        double bonus = 0.0;

        // Iterate through all employees to find technicians reporting to this manager
        for (Employee* emp : allEmployees) {
            // Use dynamic_cast to safely check if the employee is a Technician
            Technician* tech = dynamic_cast<Technician*>(emp);
            if (tech != nullptr) 
            {
                
                if (tech->getManagerTaxCode() == this->getTaxCode()) {
                    // The technician's salary itself doesn't depend on the list, so we can pass an empty one.
                    bonus += 0.10 * tech->calculateSalary({}); 
                }
            }
        }

        return baseSalary + bonus;
    }

    string getResponsibilityField() const { return responsibilityField; }
};