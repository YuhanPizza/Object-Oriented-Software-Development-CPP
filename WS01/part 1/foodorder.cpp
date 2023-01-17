#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "foodorder.h"


using namespace std;
double g_taxrate = 0;
double g_dailydiscount = 0;
static int counter = 1;
namespace sdds {
	
	FoodOrder::FoodOrder() {
		food[25] = {};
		 name[10] = {};
		 price = { 0.0 };
		 special = false;
	};

	void FoodOrder::read(istream& file) {
		if (file) {
			char a;
			file.getline(name, 10, ',');
			file.getline(food, 25, ',');
			file >> price;
			file.ignore();
			file >> a;
			if (a == 'Y') {
				special = true;
			}
			else {
				special = false;
			}
		file.ignore(1000, '\n');
		}
	};

	void FoodOrder::display() {
		cout.width(2);
		cout.setf(ios::left);
		cout << counter;
		cout.unsetf(ios::left);
		cout << ". ";
		if (strcmp(name, "\0") == 0) {
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
				cout << std::setprecision(2) << fixed;
				cout << (price)+(price * g_taxrate) - g_dailydiscount;
			}
			cout << "\n";
		}
		counter++;
	};

	FoodOrder& FoodOrder::operator=(const FoodOrder &right) {
		if (this != &right) { //if they are not the same object
			if (right.name[0] != '\0') { //if right.name exists 
				strcpy(this->name,right.name);  //store right.name to current object.name
				if (right.food[0] != '\0') { //if right.food exists 
					strcpy(this->food,right.food); //store right.food to current object.name
					if (right.price != 0) {
						this->price = right.price;
						this->special = right.special;
					}
				}
			}
		}
		return *this;
	};
	FoodOrder::FoodOrder(const FoodOrder& src) {
		*this = src;
	}
}