/*Description of the situation and requirements
For all company employees, the following information is known : personal data(tax code, first name, last name), hiring date, and any other data necessary to solve the problem.
The professional roles we distinguish are :
*Technicians, who add to their personal data a specialization field(hardware or software).
Technicians report to a manager and receive a monthly salary based on their seniority :
€1500 for technicians with less than 10 years of seniority
€1600 for technicians with 10 years of seniority or more.
*Managers, who add to their personal data the field of responsibility.
Each manager has a salary of €2000 plus a bonus equal to 10 % of the salary of each technician who directly reports to them.
*Executives, who add to their personal data the name of the division they manage.
Each executive has a salary of €2500 plus a bonus equal to 10 % of the salaries of all company employees.
Requirements:
Develop an application that reads the company employee data from a CSV text file(provided as an attachment to the exam) and builds the necessary classes(methods and attributes) to store the data and answer the following requests.
Note: the same employee cannot be entered twice.
The main program will call the company methods(characterized by the company name and the ArrayList of all employees...) required to answer the following requests*/
#include <iostream>
#include <vector>
#include "Company.h"

using namespace std;

int main()
{
	Company company("My Company");
	// Load employees from file
	vector<Employee*> employees = company.getEmployees();
	// print all employees details
	company.printAllEmployees();
	return 0;
}

