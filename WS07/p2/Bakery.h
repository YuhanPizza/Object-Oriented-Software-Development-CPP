/*
*****************************************************************************
			Workshop - #7
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <string>
#include <vector>
#include <algorithm>
#include <list>

namespace sdds {
	enum class BakedType {BREAD,PASTERY};
	struct BakedGood {
		BakedType m_type{}; //BREAD OR PASTERY
		std::string m_desc{}; //description
		size_t m_life{0u}; //shelflife
		size_t m_count{0u}; //stock
		double m_price{0.0}; //price
	};
	class Bakery {
		std::vector<BakedGood> m_goods;
	public:
		Bakery(const char* filesrc);

		//display method
		void showGoods(std::ostream& os)const;
		//sort method
		void sortBakery(const std::string& field);
		//modifier function
		std::vector<BakedGood> combine(Bakery& other);
		//query functions
		bool inStock(const std::string& desc, const BakedType& type) const; 
		std::list<BakedGood> outOfStock(const BakedType& type) const;
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& src);
}
#endif
