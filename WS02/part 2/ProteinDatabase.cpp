/*
*****************************************************************************
			Workshop - #2
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
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
					if (temp[0] == '>') {
						p_current++; //this is how it stores it the count
					}
				}
				p_string = new string[p_current]; //this basically allocates p_current number of strings so what ever p_currents value is 
												 //this will allocate that many members of strings to that array.

				ifs.clear();
				ifs.seekg(0, ios::beg);
				int i = 0;

				while (!ifs.eof()) {
					getline(ifs, temp,'\n');
					if (temp[0] == '>') { //checks if its the beggining via '>'  do some stuff 
						getline(ifs, p_string[i], '\n');
						i++;
					}
					else { //just store it in the current index 
						p_string[i-1] += temp;
					}
				}
				ifs.close();
			}
		}
	}

	//destructor
	//we know this from 244
	ProteinDatabase::~ProteinDatabase() {
		if (p_string) {
			delete[]p_string;
		}
	}

	//copy constructor
	//we know this from 244
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& org) {
		*this = org;
	}

	//copy assignment
	//we know this from 244
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
		*this = move(org); // changes the object from lvalue to rvalue so that the move operator is called.
	}

	//move assignment
	// basically doing this 
	// org  -> data 
	// this -> data 
	// org  -> null
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& org) {
		if (this != &org) { // if not the same thing 
			if (p_string) { //if this p_string is not empty clear it 
				delete[]p_string;
				p_string = nullptr;
			}
			this->p_current = org.p_current; //explained in 92 to 96 
			org.p_current = 0u;

			this->p_string = org.p_string;
			org.p_string = nullptr;
		}

		return *this;
	}

	//this just returns the size of the 
	size_t ProteinDatabase::size()const {
		return p_current;
	}

	string ProteinDatabase::operator[](size_t org) const {
		string temp = ""; //empty string 

		if (org < p_current) { // if org is less then size of the array
			temp = p_string[org]; // get the index of that aray from org
		}
		return temp; //return
	}
}