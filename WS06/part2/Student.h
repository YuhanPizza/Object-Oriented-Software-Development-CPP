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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include "Person.h"

namespace sdds {
	class Student : public Person { //derived from person base class
		std::string m_id{}; //id 
		std::string m_name{}; //name
		std::string* m_courses = nullptr; //dynamic array of string 
		size_t m_age{0u}; //age
		size_t m_count{0u}; //count determins the size of courses
	public:
		Student(std::istream& in); //constructor
		~Student(); //destructor
		Student(const Student& src) = delete; //removed copy constructor
		Student& operator=(const Student& src) = delete; //removed copy assignment operator
		//queries
		std::string status()const override; //overrides virtual functions from person
		std::string name()const override; //overrides virtual functions from person
		std::string age() const override; //overrides virtual functions from person
		std::string id() const override; //overrides virtual functions from person
		//display
		void display(std::ostream& out) const override; //overrides virtual functions from person
	};
}
#endif // !SDDS_STUDENT_H

