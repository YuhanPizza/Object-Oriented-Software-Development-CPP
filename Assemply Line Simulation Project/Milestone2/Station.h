/*
*****************************************************************************
			Milestone - #1
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include "Utilities.h"

namespace sdds {
	class Station {
		size_t m_id{0u};
		std::string m_name{};
		std::string m_desc{};
		int m_serialNumber;
		size_t m_quantity;

		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string& record);
		const std::string& getItemName()const;
		size_t getNextSerialNumber();
		size_t getQuantity()const;
		void updateQuantity();
		void display(std::ostream& out, bool full) const;
	};
}
#endif
