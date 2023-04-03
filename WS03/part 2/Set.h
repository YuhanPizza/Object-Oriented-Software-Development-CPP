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
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <cmath>
#include "Collection.h"

namespace sdds {
	template <typename T>
	class Set : public Collection<T, 100> { 
	public:
		bool add(const T& item) { 
			for (int i = 0; i < this->size(); i++) {
				if (this->operator[](i) == item) {
					return false;
				}
			}
			return Collection<T, 100>::add(item);
		}
	};

	template<>
	class Set<double> : public Collection<double, 100> { //double specialization
	public:
		bool add(const double& item) {
			for (int i = 0; i < size(); i++) { //called size() aswell
				if (std::fabs((*this)[i] - item) <= 0.01) { //overloaded subscript operator found in Collection
					//(*this)[i]; or this->operator[](i);
					return false;// if found
				}
			}
			return Collection<double, 100>::add(item); //if not found call add function of Collection class
		}
	};
}
#endif