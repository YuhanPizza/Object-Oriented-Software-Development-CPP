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
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H
#include "Person.h"
#include "Employee.h"

namespace sdds {
	class Professor : public Employee { //derived from employee base class
		std::string m_department{}; //department i mean its pretty self explanatory
	public:
		Professor(std::istream& in); //constructor
		void display(std::ostream& out) const; //display function
		std::string status()const; //query for status
		std::string department()const; //query for department
		~Professor() = default; //default constructor
	};
}
#endif
