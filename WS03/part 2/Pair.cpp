/*
*****************************************************************************
			Workshop - #3
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

namespace sdds {
	//comparison 
	bool Pair::operator==(const Pair& other) const {
		return m_key == other.m_key;
	};

	//outside a class extraction operator ostream object
	ostream& operator<<(ostream& os, const Pair& m_item) {
		os.width(20);
		os.setf(std::ios::right);
		os << m_item.getKey();
		os.unsetf(std::ios::right);
		os << ": ";
		os.setf(std::ios::left);
		os << m_item.getValue();
		os.unsetf(std::ios::left);
		return os;
	};
};