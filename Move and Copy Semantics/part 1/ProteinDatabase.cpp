#include <fstream>
#include "ProteinDatabase.h"

using namespace std;

namespace sdds {
	//single argument constructor
	ProteinDatabase::ProteinDatabase(const char* file) {
		if (file) {
			ifstream ifs(file);
			string temp;
			if (ifs) {
				//counts the number of strings present in the file
				while (getline(ifs, temp)) {
					if(temp[0]== '>'){
						p_current++; //this is how it stores it the count
					}
				}
				p_string = new string[p_current]; //this basically allocates p_current number of strings so what ever p_currents value is 
												 //this will allocate that many members of strings to that array.

				ifs.clear();
				ifs.seekg(0, ios::beg);
				int i = 0;

				while (getline(ifs, temp)) {  
					if (temp[0] == '>') { //checks if its the beggining via '>' 
						string values;
						getline(ifs,p_string[i]); //stores the next line in the fstream object to temp
						//while (temp.size() == 60) { //if temp.size is == 60 then you store taht to the p_string index i;
						//	p_string[i] += temp;
						//	getline(ifs, temp);
						//}
						i++;
					}

				}
				ifs.close();
			}
		}
	}

	//destructor
	ProteinDatabase::~ProteinDatabase() {
		if (p_string) {
			delete[]p_string;
		}
	}

	//copy constructor
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& org) {
		*this = org;
	}

	//copy assignment
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