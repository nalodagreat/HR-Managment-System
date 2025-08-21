#pragma once
#include "Employee.h"
class Technician : public Employee
{
	string specialization;
	string cfManagedByManager; // this is the tax code of the manager who manages this technician
public:
	Technician(string role, string cf, string name, string surname, Date dateOfStartWorking, string specialization, string cfManagedByManager)
		: Employee(role, cf, name, surname, dateOfStartWorking)
	{
		this->specialization = specialization;
		this->cfManagedByManager = cfManagedByManager;
	}
	string getSpecialization()
	{
		return specialization;
	}
	void setSpecialization(string specialization)
	{
		this->specialization = specialization;
	}
	string getCfManagedByManager()
	{
		return cfManagedByManager;
	}
	double calculateSalary()
	{
		int yearsOfWorking = Date::yearsSinceDate(getDateOfStartWorking());
		if (yearsOfWorking > 10)
			return 1600;
		return 1500;
	}

};

