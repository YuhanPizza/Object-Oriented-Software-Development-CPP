// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include<iostream>
#include<string>
#include<fstream>
#include<functional>

namespace sdds_ws9 {
	//Do NOT change in Cpp!
	//                    data, total_items, total_items, variable which the avg is to be stored.
	void computeAvgFactor(const int*, int, int, double&); //Computes the Average-factor from the data supplied in the first parameter.
	//                    data, total_items, total_items, computedavgFactor, variable which the computed variance is to be stored.
	void computeVarFactor(const int*, int, int, double, double&); //Computes the Variance-factor from the data supplied in the first parameter.

	class ProcessData {
		int total_items{}; //size of the array and divisor.
		int* data{}; //data.
	public:
		//Do Not Modify already existing data only add what is Missing!
		ProcessData(std::string); //recieves a filename, opens the file in binary mode, reads the total number of data elements(first 4 bytes), data-item values.
		ProcessData(const ProcessData&) = delete; //no copy constructor
		ProcessData& operator=(const ProcessData&) = delete; //no copy assignment operator
		~ProcessData();
		//operator ()
		operator bool() const;
		int operator()(std::string, double&, double&); //recieves the target-filename (data is to be written in binary format), double reference variable for average value, double reference variable for variance value
	};
	
	
}



#endif 