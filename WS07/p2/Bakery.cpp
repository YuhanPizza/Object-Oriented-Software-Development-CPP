#include "Bakery.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

namespace sdds {
	Bakery::Bakery(const char* filesrc) {
		ifstream file(filesrc);
		if (!file) {
			throw string("Error: Cannot open file.");
		}
		string line;
		while (getline(file, line)) {
			BakedGood goods;

			string typeStr = line.substr(0, 8);
			typeStr = typeStr.erase(0, typeStr.find_first_not_of(' '));
			typeStr = typeStr.erase( typeStr.find_last_not_of(' ') + 1);
			goods.m_type = (typeStr == "Bread") ? BakedType::BREAD : BakedType::PASTERY;
			goods.m_desc = line.substr(8, 20);
			goods.m_desc.erase(0, goods.m_desc.find_first_not_of(' '));
			goods.m_desc.erase(goods.m_desc.find_last_not_of(' ') + 1);
			goods.m_life = stoul(line.substr(28, 14));
			goods.m_count = stoul(line.substr(42, 8));
			goods.m_price = stod(line.substr(50, 6));
			m_goods.push_back(goods);
		}
		file.close();
	}
	void Bakery::showGoods(ostream& os)const {
		//calculate the total stock and price of goods
		size_t totalStock = 0;
		double totalPrice = 0;
		for (const auto& goods : m_goods) {
			totalStock += goods.m_count;
			totalPrice += goods.m_price;
		}
		/*The for_each function takes three arguments :
		1.The beginning of the range to iterate over "m_goods.begin()"
		2.The end of the range to iterate over "m_goods.end()"
		3.A lambda function that takes a single argument of the same type as the elements in the range "const BakedGood & goods" */
		for_each(m_goods.begin(), m_goods.end(), [&os](const BakedGood& src) { //iterates over each element in the m_goods vector and applies a lambda function to each element
			os << src << endl;
		});
		// Specifically, the capture list `[&]` means that all variables referenced inside the lambda function will be captured by reference. 
		// This allows the lambda function to access and modify variables from the outer scope.
		os << left << "Total Stock: ";
		os << right << totalStock << endl;
		os << left << "Total Price: ";
		os << right <<  fixed << setprecision(2) << totalPrice << endl;
		
	}
	void Bakery::sortBakery(const string& field) {
		if (field == "Description") {
			std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.m_desc < b.m_desc;
			});
		}
		else if (field == "Shelf") {
			std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.m_life < b.m_life;
			});
		}
		else if (field == "Stock") {
			std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.m_count < b.m_count;
			});
		}
		else if (field == "Price") {
			std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.m_price < b.m_price;
			});
		}
		else {
			throw "Error: Invalid input!";
		}
		// assign the sorted vector back to the original vector
	}
	vector<BakedGood> Bakery::combine(const Bakery& other) {
		vector<BakedGood> result(m_goods.begin(), m_goods.end());
		result.insert(result.end(), other.m_goods.begin(), other.m_goods.end());
		sort(result.begin(), result.end(), [&]( BakedGood& a, BakedGood& b) {
			return a.m_price < b.m_price;
			});
		return result;
	}
	bool Bakery::inStock(const string& desc, const BakedType& type) const {
		return any_of(m_goods.begin(), m_goods.end(), [&desc, type](const BakedGood& bg) {
			return bg.m_desc == desc && bg.m_type == type && bg.m_count > 0;
			});
	}

	list<BakedGood> Bakery::outOfStock(const BakedType& type) const {
		list<BakedGood> result;
		copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(result), [&type](const BakedGood& bg) {
			return bg.m_type == type && bg.m_count == 0;
			});
		return result;
	}
	ostream& operator<<(ostream& os, const BakedGood& src) {
		os << left << "* " << setw(10) << (src.m_type == BakedType::BREAD ? "Bread" : "Pastry") << " * ";
		os << setw(20) << src.m_desc << " * ";
		os << setw(5) << src.m_life << " * ";
		os << setw(5) << src.m_count << " * ";
		os << right <<fixed << setprecision(2) << setw(8) << src.m_price << " * ";
		return os;
	}

}