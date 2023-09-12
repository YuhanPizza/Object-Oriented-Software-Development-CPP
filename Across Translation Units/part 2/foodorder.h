/*
*****************************************************************************
							Workshop - #1
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <fstream>
#include <iostream>

//external variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder {
		char* food{};
		char name[10]{};
		double price{};
		bool special{};
		void setFood(const char* g_desc);
		void safeEmpty(); //safe Empty state
	public:
		FoodOrder() = default; //default constructor

		//Rule of Three
		FoodOrder(const FoodOrder& src); //overloaded Constructor
		FoodOrder& operator=(const FoodOrder& right); //assignment Operator
		~FoodOrder(); //destructor
		

		void read(std::istream& in = std::cin); //istreamObject

		void display()const; //display method

		
		
	};
}
#endif
