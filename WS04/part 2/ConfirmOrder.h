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
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include <iostream>
#include <string>
#include "Toy.h"
namespace sdds {
	class ConfirmOrder {
		const Toy** m_toys{ nullptr };
		size_t m_size{ 0u };
	public:
		//default constructor
		ConfirmOrder() = default;
		//copy constructor
		ConfirmOrder(const ConfirmOrder& src);
		//copy assignment operator
		ConfirmOrder& operator=(const ConfirmOrder& src);
		//move constructor
		ConfirmOrder(ConfirmOrder&& src)noexcept;
		//move assignment operator
		ConfirmOrder& operator=(ConfirmOrder&& src)noexcept;
		//destructor
		~ConfirmOrder();

		//operators add and subtract
		ConfirmOrder& operator+=(const Toy& toy); //adds to toy stuff 
		ConfirmOrder& operator-=(const Toy& toy);

		//friend extraction operator ostream
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& C);
	};
	
}
#endif


