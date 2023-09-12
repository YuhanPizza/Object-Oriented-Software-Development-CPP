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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <stdexcept>


namespace sdds {
	class Utilities {
		size_t m_widthField{ 1u };
		static char m_delimiter;
	public:
		void setFieldWidth(size_t src);
		size_t getFieldWidth()const;
		std::string extractToken(const std::string& str, size_t& nxt_pos, bool& more);
		static void setDelimiter(char src);
		static char getDelimiter();
	};
}

#endif 
