/*
*****************************************************************************
			Milestone - #2
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Utilities.h"
#include "Station.h"

namespace sdds {
	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name{""};
		std::string m_product{""};
		size_t m_count{ 0u };
		Item** m_items{ nullptr };
		static size_t m_widthField;

	public: 
		CustomerOrder() = default;
		CustomerOrder(const std::string& src);

		//copy constructor and operator
		CustomerOrder(const CustomerOrder& src); //throws an exception if called
		CustomerOrder& operator=(const CustomerOrder& other) = delete;

		//move operator and constructor
		CustomerOrder(CustomerOrder&& src)noexcept;
		CustomerOrder& operator=(CustomerOrder&& other)noexcept;

		//destructor
		~CustomerOrder();

		//query function
		bool isOrderFilled()const;
		bool isItemFilled(const std::string& itemName)const;

		void fillItem(Station&, std::ostream& os);

		//display function
		void display(std::ostream& os)const;
	};
}
#endif
