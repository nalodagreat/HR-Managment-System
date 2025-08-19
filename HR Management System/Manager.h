#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
#include "Date.h"
#include "Technician.h"
#include <vector>
using namespace std;
class Manager : public Employee
{
	string responsibility;
	string cfMangedByExecutives; // this is the tax code of the executive who manages this manager
	vector<Technician> vTechnicians; //list of technicians who report to this manager
public:
	Manager(string role, string cf, string name, string surname, Date dateOfStartWorking, string responsibility,string cfMangedByExecutives)
		: Employee(role, cf, name, surname, dateOfStartWorking)
	{
		this->responsibility = responsibility;
		this->cfMangedByExecutives = cfMangedByExecutives;
	}
	string getResponsibility() {
		return responsibility;
	}
	void setResponsibility(string responsibility) {
		this->responsibility = responsibility;
	}
	void addTechnician(Technician technician)
	{
		// Check if the technician is already managed by this manager
		for (Technician tech : vTechnicians) {
			if (tech.getCfManagedByManager() == technician.getCfManagedByManager()) {
				return; // Technician already exists in the list
			}
		}
		vTechnicians.push_back(technician);
	}
	vector<Technician> getTechnicians() {
		return vTechnicians;
	}
	
    void addTechnicianToManagerList(Technician technician )
	{
		vTechnicians.push_back(technician);
	}
	double calculateSalary() {
		double salary = 2000.0; // base salary for manager
		for (Technician tech : vTechnicians) {
			if (tech.getCfManagedByManager() == this->getCf()) {
				salary *= 0.1;
			}
		}
		return salary;
	}


};

