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
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>

namespace sdds {
	class Pair {
		std::string m_key;
		std::string m_value;

	public:
		//constructor
		Pair() : m_key(), m_value() {};
		Pair(const std::string& key, const std::string& value) : m_key(key), m_value(value) {};
		const std::string& getKey() const { return m_key; } //used in query for extraction 
		const std::string& getValue() const { return m_value; } //used in query for extraction
		bool operator==(const Pair& other) const;
	};
	std::ostream& operator<<(std::ostream& os, const Pair& m_item); //extraction operator ostream

} 

#endif 