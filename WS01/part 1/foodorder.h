#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <fstream>
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds{
	class FoodOrder{
		char food[25];
		char name[10];
		double price;
		bool special;
	public:
		FoodOrder();
		FoodOrder(const FoodOrder& src);
		void read(std::istream& file = std::cin);
		void display();
		FoodOrder& operator=(const FoodOrder &right);
	};
}
#endif