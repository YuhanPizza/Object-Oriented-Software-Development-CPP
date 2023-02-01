#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

namespace sdds {
	//comparison 
	bool Pair::operator==(const Pair& other) const {
		return m_key == other.m_key;
	};

	//outside a class extraction operator ostream object
	ostream& operator<<(ostream& os, const Pair& m_item) {
		os.width(25);
		os.setf(std::ios::right);
		os << m_item.getKey();
		os.unsetf(std::ios::right);
		os << ": ";
		os.setf(std::ios::left);
		os << m_item.getValue();
		os.unsetf(std::ios::left);
		return os;
	};
};