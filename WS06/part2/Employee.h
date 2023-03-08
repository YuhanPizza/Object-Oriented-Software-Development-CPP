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
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include "Person.h"

namespace sdds {
	class Employee :public Person {
		std::string m_name{};
		std::string m_id{};
		size_t m_age{0u};
	public:
		Employee(std::istream& in);

		std::string status() const override;// : a query that returns the string Employee
		std::string name() const override;// : a query that returns the name of the employee
		std::string id() const override;// : a query that returns the id of the employee
		std::string age() const override;// : a query that returns the age of the employee
		void display(std::ostream& out) const override;// display function

		virtual ~Employee() = default;

	};
}

#endif
