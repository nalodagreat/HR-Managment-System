#pragma once
#include "Employee.h"
class Technician : public Employee
{
	string specialization;
public:
	Technician(string role, string cf, string name, string surname, Date dateOfStartWorking, string specialization)
		: Employee(role, cf, name, surname, dateOfStartWorking)
	{
		this->specialization = specialization;
	}
	string getSpecialization() 
	{
		return specialization;
	}
	void setSpecialization(string specialization)
	{
		this->specialization = specialization;
	}

};

