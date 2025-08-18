#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Employee
{
	string role;
	string cf;
	string name;
	string surname;
	Date dateOfStartWorking;
public:
	Employee(string role, string cf, string name, string surname, Date dateOfStartWorking)
	{
		this->role = role;
		this->cf = cf;
		this->name = name;
		this->surname = surname;
		this->dateOfStartWorking = dateOfStartWorking;
	}
	string getRole()
	{
		return role;
	}
	string getCf()
	{
		return cf;
	}
	string getName()
	{
		return name;
	}
	string getSurname()
	{
		return surname;
	}
	Date getDateOfStartWorking()
	{
		return dateOfStartWorking;
	}
	void setRole(string role)
	{
		this->role = role;
	}
	void setCf(string cf)
	{
		this->cf = cf;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setDateOfStartWorking(Date dateOfStartWorking)
	{
		this->dateOfStartWorking = dateOfStartWorking;
	}

};

