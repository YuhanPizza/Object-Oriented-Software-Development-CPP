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
			if (typeStr == "Bread") {
				goods.m_type = BakedType::BREAD;
			}
			else if(typeStr == "Pastry") {
				goods.m_type = BakedType::PASTRY;
			}
			else {
				goods.m_type = BakedType::BREAD;
				throw string("Error: Invalid BakedType!.");
				
			}
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
		/*The for_each function takes three arguments :
		1.The beginning of the range to iterate over "m_goods.begin()"
		2.The end of the range to iterate over "m_goods.end()"
		3.A lambda function that takes a single argument of the same type as the elements in the range "const BakedGood & goods" */
		for_each(m_goods.begin(), m_goods.end(), [&](const BakedGood& src) { //iterates over each element in the m_goods vector and applies a lambda function to each element
			os << left << "* " << setw(10) << (src.m_type == BakedType::BREAD ? "Bread" : "Pastry") << " * ";
			os << setw(20) << src.m_desc << " * ";
			os << setw(5) << src.m_life << " * ";
			os << setw(5) << src.m_count << " * ";
			os << right << fixed << setprecision(2) << setw(8) << src.m_price << " * " << endl;
		});
		// Specifically, the capture list `[&]` means that all variables referenced inside the lambda function will be captured by reference. 
		// This allows the lambda function to access and modify variables from the outer scope.
	}
	ostream& operator<<(ostream& os, const BakedGood& src) {
		os << left << "* " << setw(10) << (src.m_type == BakedType::BREAD ? "Bread" : "Pastry") << " * ";
		os << setw(20) << src.m_desc << " * ";
		os << setw(5) << src.m_life << " * ";
		os << setw(5) << src.m_count << " * ";
		os << right <<fixed << setprecision(2) << setw(8) << src.m_price << " * " << endl;
		return os;
	}

}