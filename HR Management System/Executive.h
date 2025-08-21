#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
#include "Date.h"
#include <vector>
using namespace std;
class Executive : public Employee
{
	string divisionName; // name of the division managed by the executive
	vector<Employee> vEmployees; // list of employees in the company
public:
	Executive(string role, string cf, string name, string surname, Date dateOfStartWorking, string divisionName)
		: Employee(role, cf, name, surname, dateOfStartWorking)
	{
		this->divisionName = divisionName;
	}
	string getDivisionName() {
		return divisionName;
	}
	void setDivisionName(string divisionName) {
		this->divisionName = divisionName;
	}
	void addEmployee(Employee employee) {
		vEmployees.push_back(employee);
	}
	vector<Employee> getEmployees() {
		return vEmployees;
	}
	double calculateSalary() {
		double salary = 2500.0; // base salary for executive
		
		for (Employee emp : vEmployees) 
		{
			if (emp.getRole() == "Executive" && emp.getCf() != this->getCf())
			{
				salary = emp .calculateSalary()*0.1; // 10% bonus for each executive
			}
		}
		return salary;
	}
	
};

