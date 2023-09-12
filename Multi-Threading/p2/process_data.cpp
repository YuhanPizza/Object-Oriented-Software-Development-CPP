// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
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


#include "process_data.h"

namespace sdds_ws9 {

	// The following function receives array (pointer) as the first argument, number of array 
	//   elements (size) as second argument, divisor as the third argument, and avg as fourth argument. 
	//   size and divisor are not necessarily same. When size and divisor hold same value, avg will 
	//   hold average of the array elements. When they are different, avg will hold a value called 
	// 	 as average-factor. For part 1, you will be using same value for size and double. Use of 
	//   different values for size and divisor will be useful for multi-threaded implementation in part-2. 
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}
	// The following function receives array (pointer) as the first argument, number of array elements  
	//   (size) as second argument, divisor as the third argument, computed average value of the data items
	//   as fourth argument, and var as fifth argument. Size and divisor are not necessarily same as in the 
	//   case of computeAvgFactor. When size and divisor hold same value, var will get total variance of 
	//   the array elements. When they are different, var will hold a value called as variance factor. 
	//   For part 1, you will be using same value for size and double. Use of different values for size 
	//   and divisor will be useful for multi-threaded implementation in part-2. 
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::binary); //ifstream object 'file' opens the 'filename' in 'binary mode'

		if (!file) { //if file was not sucessfully opened.
			total_items = 0;
			data = nullptr;
			return;
		}
		//read function stores in total_items. the reinterpret_cast<char*> used to convert the memory address of 'total_items' from an int pointer to a char to match the argument type of 'read()'
		file.read(reinterpret_cast<char*>(&total_items), sizeof(int)); //2nd argument of 'read()'function is the number of bytes to read. The 'sizeof(total_items)' returns the size of the int variable 'total_items' in bytes.
																						 //Since an int typically uses 4 bytes of memory, the read function reads the next 4 bytes from the input file,which is the total number of data elements in the file.

		data = new int[total_items]; //int array data is created with a size of total_items.

		for (int i = 0; i < total_items; ++i) { //used to read each element of 'data' from the file using 'read()'.
			//reinptepret_cast is used again to convert memory address of 'data[i]' from int to char to march the expected arguments of read function.
			file.read(reinterpret_cast<char*>(&data[i]), sizeof(int));
		}
		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		if (data) {
			delete[] data;
		}
		if (averages) {
			delete[] averages;
		}
		if (variances) {
			delete[] variances;
		}
		if (p_indices) {
			delete[] p_indices;
		}
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string filename, double& avg, double& var) {
		if (!data) { // if data is null
			throw std::string("Data cannot be retrieved!"); // return 0 as an indication of failure
		}
		std::vector<std::thread>threads(num_threads);
		//match the arguments for the function you are binding it to so you dont have to include variables that are repeated
		auto computeAvgFactorBind = std::bind(&computeAvgFactor, std::placeholders::_1, std::placeholders::_2, total_items, std::placeholders::_3);

		for (auto i = 0; i < num_threads; i++) {
			threads[i] = std::thread(computeAvgFactorBind, &data[p_indices[i]], p_indices[i + 1] - p_indices[i], std::ref(averages[i]));
		}
		for (int i = 0; i < num_threads; i++) {
			threads[i].join();
			avg += averages[i];
		}
		auto computeVarFactorBind = std::bind(&computeVarFactor, std::placeholders::_1, std::placeholders::_2, total_items, std::placeholders::_3, std::placeholders::_4);
		for (auto i = 0; i < num_threads; i++) {
			threads[i] = std::thread(computeVarFactorBind, &data[p_indices[i]], p_indices[i + 1] - p_indices[i], avg, std::ref(variances[i]));
		}
		for (int i = 0; i < num_threads; i++) {
			threads[i].join();
			var += variances[i];
		}

		std::ofstream file(filename, std::ios::binary);
		if (!file.is_open()) {
			throw std::string("File cannot be opened!");
		}
		file.write(reinterpret_cast<char*>(&total_items), sizeof(int));
		for (auto i = 0; i < total_items; i++) {
			file.write(reinterpret_cast<char*>(&data[i]), sizeof(int));
		}

		file.close();

		return 0;
	}
}