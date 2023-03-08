#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include "Person.h"

namespace sdds {
	class Employee :public Person {
		std::string m_name{};
		std::string m_id{};
		size_t m_age{};
	public:
		Employee(std::istream& in = std::cin);

		std::string status() const override;// : a query that returns the string Employee
		std::string name() const override;// : a query that returns the name of the employee
		std::string id() const override;// : a query that returns the id of the employee
		std::string age() const override;// : a query that returns the age of the employee
		void display(std::ostream& out) const override;// : a query that inserts in the first parameter the content of the employee object in the format

	};
}

#endif
