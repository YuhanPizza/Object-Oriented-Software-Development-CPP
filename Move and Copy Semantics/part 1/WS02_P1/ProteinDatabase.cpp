#include <fstream>
#include "ProteinDatabase.h"

using namespace std;

namespace sdds {
	ProteinDatabase::ProteinDatabase(const char* file) {
		if (file) {
			ifstream in(file);
			string temp;
			if (in) {
				while (getline(in, temp, ' '));
				p_current++;

				p_string = new string[p_current];

				in.clear();
				in.seekg(0, ios::beg);

				int i = 0;
				while (getline(in, p_string[i], ' '));
				i++;
			}
		}
	}

	ProteinDatabase::~ProteinDatabase() {
		if (p_string) {
			delete[]p_string;
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& org) {
		*this = org;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& org) {
		if (this != &org) {
			if (p_string) { //if p_string has value clear it 
				delete[]p_string;
				p_string = nullptr;
			}

			this->p_current = org.p_current;

			this->p_string = new string[p_current];
			for (auto i = 0u; i < p_current; ++i) {
				this->p_string[i] = org.p_string[i];
			}
		}

		return *this;
	}

	//move constructor
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& org) {
		*this = move(org);
	}

	//move assignment
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& org) {
		if (this != &org) {
			if (p_string) {
				delete[]p_string;
				p_string = nullptr;
			}
			this->p_current = org.p_current;
			org.p_current = 0u;

			this->p_string = org.p_string;
			org.p_string = nullptr;
		}

		return *this;
	}

	size_t ProteinDatabase::size()const {
		return p_current;
	}

	string ProteinDatabase::operator[](size_t org) const {
		string temp = "";

		if (org < p_current) {
			temp = p_string[org];
		}
		return temp;
	}
}