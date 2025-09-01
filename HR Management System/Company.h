
#pragma once

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include <fstream>  // For file operations
#include <sstream>  // For parsing lines
#include <iostream>

#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "Executive.h"

using namespace std;

class Company {
private:
    string companyName;
    vector<unique_ptr<Employee>> employees;

    // Helper to check for duplicate employees
    bool employeeExists(const string& taxCode) {
        for (const auto& emp : employees) {
            if (emp->getTaxCode() == taxCode) {
                return true;
            }
        }
        return false;
    }

public:
    Company(const string& name) : companyName(name) {}

    void loadEmployeesFromCSV(const string& filename) {
        ifstream file(filename);
        string line;

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        while (getline(file, line)) {
            stringstream ss(line);
            string segment;
            vector<string> segments;

            while(getline(ss, segment, ',')) {
                segments.push_back(segment);
            }

            if (segments.empty()) continue;

            string type = segments[0];
            string taxCode = segments[1];

            if (employeeExists(taxCode)) {
                cout << "Warning: Duplicate employee with tax code " << taxCode << " found. Skipping." << endl;
                continue;
            }

            if (type == "Technician" && segments.size() >= 7) {
                employees.push_back(make_unique<Technician>(segments[1], segments[2], segments[3], segments[4], segments[5], segments[6]));
            } else if (type == "Manager" && segments.size() >= 6) {
                employees.push_back(make_unique<Manager>(segments[1], segments[2], segments[3], segments[4], segments[5]));
            } else if (type == "Executive" && segments.size() >= 6) {
                employees.push_back(make_unique<Executive>(segments[1], segments[2], segments[3], segments[4], segments[5]));
            }
        }
        file.close();
        cout << "Successfully loaded " << employees.size() << " employees from " << filename << endl;
    }

    void printAllSalaries() {
        cout << "\n--- Full Salary Report for " << companyName << " ---" << endl;
        vector<Employee*> raw_employees = getRawEmployeePointers();

        for (const auto& emp : employees) {
            printEmployeeSalary(emp.get(), raw_employees);
        }
        cout << "------------------------------------" << endl;
    }

    void printSalaryByTaxCode(const string& taxCode) {
        cout << "\n--- Searching for employee with Tax Code: " << taxCode << " ---" << endl;
        Employee* found_emp = nullptr;
        for (const auto& emp : employees) {
            if (emp->getTaxCode() == taxCode) {
                found_emp = emp.get();
                break;
            }
        }

        if (found_emp) {
            printEmployeeSalary(found_emp, getRawEmployeePointers());
        } else {
            cout << "Employee not found." << endl;
        }
        cout << "----------------------------------------------------" << endl;
    }

    void printTotalSalaryCost() {
        cout << "\n--- Total Monthly Salary Cost ---" << endl;
        double totalCost = 0.0;
        vector<Employee*> raw_employees = getRawEmployeePointers();
        for (const auto& emp : employees) {
            totalCost += emp->calculateSalary(raw_employees);
        }
        cout << "Total cost for " << employees.size() << " employees: " << totalCost << " EUR" << endl;
        cout << "---------------------------------" << endl;
    }

    void printEmployeesByRole() {
        cout << "\n--- Employees by Role ---" << endl;
        vector<Employee*> raw_employees = getRawEmployeePointers();

        cout << "\n** Executives **" << endl;
        for (const auto& emp : employees) {
            if (dynamic_cast<Executive*>(emp.get())) {
                printEmployeeSalary(emp.get(), raw_employees);
            }
        }

        cout << "\n** Managers **" << endl;
        for (const auto& emp : employees) {
            if (dynamic_cast<Manager*>(emp.get())) {
                printEmployeeSalary(emp.get(), raw_employees);
            }
        }

        cout << "\n** Technicians **" << endl;
        for (const auto& emp : employees) {
            if (dynamic_cast<Technician*>(emp.get())) {
                printEmployeeSalary(emp.get(), raw_employees);
            }
        }
        cout << "-------------------------" << endl;
    }

private:
    // Helper to get raw pointers for calculations
    vector<Employee*> getRawEmployeePointers() {
        vector<Employee*> raw_employees;
        for(const auto& emp : employees) {
            raw_employees.push_back(emp.get());
        }
        return raw_employees;
    }

    // Helper to print a single employee's salary
    void printEmployeeSalary(Employee* emp, const vector<Employee*>& all_emps) {
        cout << "- " << emp->getFirstName() << " " << emp->getLastName() 
                << " (" << emp->getTaxCode() << "): " 
                << emp->calculateSalary(all_emps) << " EUR" << endl;
    }
};
