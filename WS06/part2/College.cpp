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
#include "College.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
	College::~College() {
		for (auto p : m_persons)
			delete p;
	}

	College& College::operator+=(Person* thePerson) {
		m_persons.push_back(thePerson); //this is how you add to the vector
		return *this;
	}

	void College::display(ostream& out)const {
		out << "------------------------------------------------------------------------------------------------------------------------" << endl;
		out << "|                                        Test #1 Persons in the college!                                               |" << endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << endl;
		for (const auto& p : m_persons) {
			p->display(out);
			out << endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n"
			<< "|                                        Test #2 Persons in the college!                                               |\n"
			<< "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto itr = m_persons.begin(); itr != m_persons.end(); ++itr) { 
			//(*itr)->display(out);
			out << "| ";
			out << left << setw(10) << (*itr)->status();
			out << "| " << left << setw(10) << (*itr)->id();
			out << "| " << left << setw(20) << (*itr)->name();
			out << " | " << left << setw(3) << (*itr)->age() << " |";
			out << endl;

		}
			
		out << "------------------------------------------------------------------------------------------------------------------------\n";
	}
}