/*
*****************************************************************************
			Milestone - #3
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> m_activeLine; // the collection of workstations for the current assembly line.
		size_t m_cntCustomerOrder{ 0u }; // the total number of customer order objects.
		Workstation* m_firstStation{ nullptr }; //points to the first active station on the current line.

	public:
		//default constructor 
		LineManager() = default;
		//argument constructor
		LineManager(const std::string& file, const std::vector<Workstation*>& station); // this constructor recieves the name of the file that identifies the active stations on the assembly & collection of workstations available.

		//modifiers
		void reorderStations(); // This modifier reorders the workstations present in the instance variable m_activeLine(loaded by the constructor) and stores the reordered collection in the same instance variable.
		bool run(std::ostream& os); // This modifier prefomrs one iteration of operations on all the workstations in the current assembly line.

		//query
		void display(std::ostream& os)const;//this query displays all active stations on the assembly line in their current order.
	};

}
#endif
