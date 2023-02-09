/*
*****************************************************************************
			Workshop - #4
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <string>
#include <cstring>
#include "Toy.h"

namespace sdds {
	class Child {
		std::string m_cName{'\0'}; //child name 
		size_t m_age{ 0u }; //child age made into a unsinged int cuz bruh a kid cant be negative years old 
		const Toy** m_toys{ nullptr }; //child toy array
		size_t m_tCount{ 0u }; //size of the toy array

	public:
		//default constructor
		Child() = default;
		// Constructor
		Child(std::string g_name, size_t g_age,const Toy* toys[], size_t count);

		//------- Rule of 5 ------------
		//copy constructor
		Child(const Child& src);
		//Move Constructor
		Child(Child&& src)noexcept; // noexcept is a C++ keyword that is used to specify whether a function can throw an exception or not.
		//Copy Assignment Operator
		Child& operator=(const Child& src);
		//move Assignment Operator
		Child& operator=(Child&& src)noexcept; // noexcept indicates that the move operation is guaranteed to not throw any exceptions.
		//Destructor
		~Child();
		//------------------------------ 


		//Query
		size_t size() const; //RETURNS THE SIZE 

		//Friend Ostream Extraction operator
		friend std::ostream& operator<<(std::ostream& os, const Child& src);
	};
}
#endif
