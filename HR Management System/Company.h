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
	vector<Employee*> vEmployees; // list of employees in the company
	vector<Employee*> loadEmployeesFromFile(string filename = "employees.txt") {
		vector<Employee*> employees;
		ifstream file(filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << filename << endl;
			return employees; // return empty vector if file cannot be opened
		}
		string line;
		while (getline(file, line)) 
		{
			vector<string> data = clsString::Split(line,";");
			if (data.size() < 5) 
				continue;
			string role = data[0];
			string cf = data[1];
			string name = data[2];
			string surname = data[3];
			Date dateOfStartWorking= Date::convertStringToDat(data[4]);
			if (role == "Technician") {
				string specialization = data[5];
				string cfManagedByManager = data[6];
				Technician *technician=new Technician(role, cf, name, surname, dateOfStartWorking, specialization, cfManagedByManager);
				employees.push_back(technician);
			}
			else if (role == "Manager") {
				string responsibility = data[5];
				string cfManagedByExecutives = data[6];
				Manager * manager=new Manager(role, cf, name, surname, dateOfStartWorking, responsibility, cfManagedByExecutives);
				employees.push_back(manager);
			}
			else if (role == "Executive") {
				string divisionName = data[5];
				Executive *executive= new Executive(role, cf, name, surname, dateOfStartWorking, divisionName);
				employees.push_back(executive);
			}
		}
		file.close();
		return employees;
	}
	
public:
	Company(string companyName) : companyName(companyName) {}
	string getCompanyName() 
	{
		return companyName;
	}
	void setCompanyName(string companyName) {
		this->companyName = companyName;
	}
	bool addEmployee(Employee *employee) 
	{
		if (employeeExists(employee->getCf())) {
			/*cout << "Employee with CF " << employee.getCf() << " already exists." << endl;*/
			return false; // Employee already exists, do not add
		}
		vEmployees.push_back(employee);
		return true;
	}
	vector<Employee*> getEmployees()
	{
		vEmployees = loadEmployeesFromFile(); // Load employees from file
		return vEmployees;
	}
	bool employeeExists(string cf) {
		for (Employee *emp : vEmployees) {
			if (emp->getCf() == cf) {
				return true; // Employee already exists
			}
		}
		return false; // Employee does not exist
	}

	//todo:print all employees deatails in the company
	void printAllEmployees() {
		for (Employee *emp : vEmployees) {
			cout << "Role: " << emp->getRole() << ", CF: " << emp->getCf()
				<< ", Name: " << emp->getName() << ", Surname: " << emp->getSurname()
				<< ", Date of Start Working: " << emp->getDateOfStartWorking().dateTostring() << endl;
			if (emp->getRole() == "Technician") {
				cout << "Specialization: " <<  emp->getSpecialization()
					<< ", Managed by Manager CF: " <<  emp->getCfManagedByManager()
					<< ", Salary: " <<  emp->calculateSalary() << endl;
			}
			else if (emp->getRole() == "Manager") {
				cout << "Responsibility: " <<  emp->getResponsibility()
					<< ", Managed by Executive CF: " <<  emp->getCfManagedByExecutives()
					<< ", Salary: " <<  emp->calculateSalary() << endl;
			}
			else if (emp->getRole() == "Executive") {
				// to avoid memory leak, we should not use new here, instead we can use stack allocation
				cout << "Division Name: " <<  emp->getDivisionName()
					<< ", Salary: " <<  emp->calculateSalary() << endl;

			}
		}
	}
};