// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant
/*
*****************************************************************************
			Workshop - #9
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include<iostream>
#include<string>
#include<fstream>
#include<functional>
#include<vector>
#include<thread>
#include <algorithm>
#include <numeric>

namespace sdds_ws9 {
	//                    data, total_items, total_items, variable which the avg is to be stored.
	void computeAvgFactor(const int*, int, int, double&);//Computes the Average-factor from the data supplied in the first parameter.
	//                    data, total_items, total_items, computedavgFactor, variable which the computed variance is to be stored.
	void computeVarFactor(const int*, int, int, double, double&);//Computes the Variance-factor from the data supplied in the first parameter.
	class ProcessData {
		int total_items{};
		int* data{};
		// Following parameters are included to be used for managing multi-threaded 
		//  computation in the operator() function. 
		int num_threads{ 0 }; // to hold number of threads 
		double* averages{ nullptr }; // to hold average factors 
		double* variances{ nullptr }; // to hold variance factors
		int* p_indices{ nullptr }; // to hold partitioning indices
	public:
		ProcessData(std::string, int n_threads);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(std::string, double&, double&);
	};
	
	
}



#endif 