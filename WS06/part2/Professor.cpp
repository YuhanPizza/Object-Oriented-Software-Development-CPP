/*
*****************************************************************************
			Workshop - #6
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Professor.h"
#include <iomanip>


using namespace std;
namespace sdds {
	Professor::Professor(istream& in) : Employee(in) {
		string department;
		getline(in, department, '\n');
		auto removeSpace = [](string& src) {
			bool exit = false;

			while (!exit) {
				if (src[0] == ' ')
					src.erase(0, src.find_first_not_of(' '));
				else if (src[src.length() - 1] == ' ')
					src.erase(src.find_last_not_of(' ') + 1);
				else
					exit = true;
			}

			return src;
		};
		department = removeSpace(department);
		m_department = department;
	}
	void Professor::display(ostream& out)const {
		Employee::display(out);
		out << m_department << "| Professor";
	}

	string Professor::status()const {
		return "Professor";
	}

	string Professor::department()const {
		return m_department;
	}
}