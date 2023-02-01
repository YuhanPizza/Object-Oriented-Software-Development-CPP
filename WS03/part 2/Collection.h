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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include "Pair.h"

namespace sdds {
	//The capacity is set to 100 by default as a value for the maximum number of items that can be stored in the collection
	template <typename T, size_t CAPACITY = 100> 
	class Collection{
		T m_items[CAPACITY]{};
		size_t m_size = 0;
		static T m_dummy; //dummy is static soo it can be used in other specialization

	public:
		Collection() {}
		virtual ~Collection() {};
		int size() const { 
			return m_size; 
		}
		void display(std::ostream& os = std::cout) const {
			os.fill('-');
			os.width(22);
			os << "-" << std::endl;
			os << "|" << " Collection Content " << "|" << std::endl;
			os.width(22);
			os << "-" << std::endl;
			os.fill(' ');
			for (int i = 0; i < int(m_size); i++) {
				os << m_items[i] << std::endl;
			}
			os.fill('-');
			os.width(22);
			os << "-" << std::endl;
			os.fill(' ');
		}
		//made viral for polymorphism
		virtual bool add(const T& item) {
			if (m_size < CAPACITY) {
				m_items[m_size++] = item;
				return true;
			}
			return false;
		}
		//overloaded subscript object that returns the m_items value based on int index
		T operator[](int index) const {
			if (index >= 0 && index < int(m_size)) {
				return m_items[index];
			}
			return m_dummy;
		}
	};

	template<typename T, size_t CAPACITY> 
	T Collection<T,CAPACITY>::m_dummy{}; //for T data type specialization

	template<>
	Pair Collection<Pair, 100>::m_dummy{"No Key", "No Value"}; //for pair data type specialization

}
#endif // COLLECTION_H

