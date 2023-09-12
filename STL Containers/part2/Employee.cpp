/*
*****************************************************************************
			Workshop - #6
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Employee.h"
#include <iomanip>

using namespace std;

namespace sdds {
	Employee::Employee(istream& in) {
		string name, age, id;
		auto removeSpace = [](string& src) {
			bool exit = false;

			while (!exit) {
				if (src[0] == ' ')
					src.erase(0, src.find_first_not_of(' '));
				else if (src[src.length() - 1] == ' ')
					src.erase(src.find_last_not_of(' ') + 1);
				else
					exit = true;
			}

			return src;
		};
		getline(in, name, ',');
		getline(in, age, ',');
		getline(in, id, ',');
		m_name = removeSpace(name);
		try {
			m_age = stoul(age);
		}
		catch (...) {
			string mv = m_name + "++Invalid record!";
			throw mv;
		}
		id = removeSpace(id);
		if (id.empty() || id[0] != 'E') {
			throw m_name + "++Invalid record!";
		}
		m_id = id;
	};
	string Employee::status() const {// : a query that returns the string Employee
		return "Employee";
	};
	string Employee::name() const {// : a query that returns the name of the employee
		return this->m_name;
	};
	string Employee::id() const {// : a query that returns the id of the employee
		return (*this).m_id;
	};
	string Employee::age() const {// : a query that returns the age of the employee
		return to_string(m_age);
	}
	void Employee::display(ostream& out) const {
		out << "| ";
		out << left << setw(10) << "Employee"
			<< "| " << left << setw(10) << m_id
			<< "| " << left << setw(20) << m_name
			<< " | " << left << setw(3) << m_age <<" |";

	}
}