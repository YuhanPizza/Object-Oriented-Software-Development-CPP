#include "College.h"
#include <iostream>

using namespace std;

namespace sdds {
	College::~College() {
		for (auto p : m_persons)
			delete p;
	}

	College& College::operator+=(Person* thePerson) {
		m_persons.push_back(thePerson);
		return *this;
	}

	void College::display(ostream& out)const {
		size_t count = 1;
		out << "------------------------------------------------------------------------------------------------------------------------\n"
			<< "|                                        Test #1  Persons in the college!                                               |\n"
			<< "------------------------------------------------------------------------------------------------------------------------\n";
		for (const auto& p : m_persons) {
			out << "| ";
			p->display(out);
			out << "|\n";
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n"
			<< "|                                        Test #2 Persons in the college!                                               |\n"
			<< "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto itr = m_persons.begin(); itr != m_persons.end(); ++itr) {
			out << "| ";
			(*itr)->display(out);
			out << "|\n";
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n";
	}
}