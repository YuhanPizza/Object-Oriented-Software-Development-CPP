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
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"

namespace sdds {
	class College {
		std::vector<Person*> m_persons;
	public:
		College(const College&) = delete;
		College& operator=(const College&) = delete;

		College() = default;
		~College();

		College& operator+=(Person* thePerson);
		void display(std::ostream& out) const;

		template<typename T>
		void select(const T& test, std::list<const Person*>& persons) {
			for (const auto& p : m_persons) { //loop
				if (test(p)) { //checks whether they are of the same class
					persons.push_back(p); //this is how you add to the list
				}
			}
		}
	};
}
#endif
