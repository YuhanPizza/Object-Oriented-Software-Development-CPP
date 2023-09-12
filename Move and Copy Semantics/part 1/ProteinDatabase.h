#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <iostream>
#include <string>

namespace sdds {
	class ProteinDatabase {
		size_t p_current{ 0u };
		std::string* p_string{ nullptr };

	public:
		ProteinDatabase() = default;
		ProteinDatabase(const char* file);
		
		//rule of 5	
		~ProteinDatabase(); //destructor
		ProteinDatabase(const ProteinDatabase& org); //copy constructor 
		ProteinDatabase& operator=(const ProteinDatabase& org); //copy assignment
		ProteinDatabase(ProteinDatabase&& org); //move constructor
		ProteinDatabase& operator=(ProteinDatabase&& org); //move operator

		size_t size()const;
		std::string operator[](size_t) const;
	};
}
#endif 
