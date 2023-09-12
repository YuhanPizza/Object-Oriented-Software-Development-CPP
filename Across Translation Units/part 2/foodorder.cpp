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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "foodorder.h"


using namespace std;
double g_taxrate = 0;
double g_dailydiscount = 0;
static int counter = 1;

namespace sdds {
	//sets object to safe empty state
	void FoodOrder::safeEmpty() {
		food = nullptr;
		name[60] = { '\0' };
		price = { 0.0 };
		special = false;
	};

	//istream object
	void FoodOrder::read(istream& in) {
		if (in) { //if gucci
			char a = 'N';
			string fDesc{};
			in.getline(name, 60, ',');
			if (in) {
				getline(in,fDesc,',');
				if (in) {
					setFood(fDesc.c_str());
					in >> price;
					in.ignore();
					in >> a;
					if (a == 'Y') {
						special = true;
					}
					else {
						special = false;
					}
				}
				in.ignore(1000, '\n'); //ignore till new line
			}
		}
	};

	void FoodOrder::display()const { //display method
		cout.width(2);
		cout.setf(ios::left);
		cout << counter;
		cout.unsetf(ios::left);
		cout << ". ";
		if (strcmp(name, "\0") == 0 || food == nullptr) {
			cout << "No Order" << endl;
		}
		else {
			cout.width(10);
			cout.setf(ios::left);
			cout << name;
			cout.unsetf(ios::left);
			cout << "|";
			cout.width(25);
			cout.setf(ios::left);
			cout << food;
			cout.unsetf(ios::left);
			cout << "|";

			cout.width(12);
			cout.setf(ios::left);
			cout << std::setprecision(2) << fixed;
			cout << (price + (price * g_taxrate));
			cout.unsetf(ios::left);
			cout << "|";

			if (special) {
				cout.width(13);
				cout << std::setprecision(2) << fixed; //sets percision to 2 decimal places
				cout << (price)+(price * g_taxrate) - g_dailydiscount; //some Maths
			}
			cout << "\n";
		}
		counter++;
	};

	FoodOrder& FoodOrder::operator=(const FoodOrder& right) {
		safeEmpty();
		if (this != &right) { //if they are not the same object
			if (strcmp(right.name,"\0")!= 0) { //if right.name exists 
				strcpy(name, right.name);  //store right.name to current object.name
				if (right.food[0] != '\0') { //if right.food exists 
					food = new char[strlen(right.food) + 1];
					this->setFood(right.food); //store right.food to current object.name
					if (right.price != 0) {
						price = right.price;
						special = right.special;
					}
				}
			}
		}
		return *this;
	};
	//copy constructor
	FoodOrder::FoodOrder(const FoodOrder& src) {
		safeEmpty();
		*this = src;
	}
	FoodOrder::~FoodOrder() {
		delete[]food;
		safeEmpty();
	}
	//created this as to pinpoint certain errors I had.
	void FoodOrder::setFood(const char* g_desc) {
		if (g_desc != nullptr) {
			int length = strlen(g_desc);
			if (food) {  // just to make extra sure its really empty
				delete[]food;
				food = nullptr;
			}
			food = new char[length + 1];
			for (int i = 0; i < length; i++) { //1 by 1 transfer.
				food[i] = g_desc[i];
			}
			food[length] = '\0'; //manually placed the null terminator 
		}
		else {
			delete[]food;
			safeEmpty();
		}
	};
}