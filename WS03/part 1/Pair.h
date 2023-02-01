#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>

namespace sdds {
	class Pair {
		std::string m_key;
		std::string m_value;

	public:
		//constructor
		Pair(): m_key(), m_value(){}
		Pair(const std::string& key, const std::string& value): m_key(key), m_value(value) {} 
		const std::string& getKey() const { return m_key; } //used in query for extraction 
		const std::string& getValue() const { return m_value; } //used in query for extraction
		bool operator==(const Pair& other) const;
	};
	std::ostream& operator<<(std::ostream& os, const Pair& m_item); //extraction operator ostream

} 

#endif SDDS_PAIR_H