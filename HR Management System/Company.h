#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include <vector>
#include <fstream>
#include "clsString.h"
#include "Employee.h"
#include "Executive.h"
#include "Manager.h"
#include "Technician.h"
using namespace std;

class Company
{
	private:
	string companyName; // name of the company
	vector<Employee> vEmployees; // list of employees in the company
	
public:
	Company(string companyName) : companyName(companyName) {}
	string getCompanyName() 
	{
		return companyName;
	}
	void setCompanyName(string companyName) {
		this->companyName = companyName;
	}
	void addEmployee(Employee employee) {
		if (employeeExists(employee.getCf())) {
			cout << "Employee with CF " << employee.getCf() << " already exists." << endl;
			return; // Employee already exists, do not add
		}
		vEmployees.push_back(employee);
	}
	vector<Employee> getEmployees()
	{

		return vEmployees;
	}
	bool employeeExists(string cf) {
		for (Employee emp : vEmployees) {
			if (emp.getCf() ==	cf) {
				return true; // Employee already exists
			}
		}
		return false; // Employee does not exist
	}
};

