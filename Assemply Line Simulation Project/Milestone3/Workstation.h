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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
	//queues(global variables) holds the orders at either end of the assembly line:
	extern std::deque<CustomerOrder> g_pending; //holds the orders to be placed onto the assembly line at the first station.
	extern std::deque<CustomerOrder> g_completed; //holds the orders that have been removed from the last station and have been completely filled.
	extern std::deque<CustomerOrder> g_incomplete; //holds the orders that have been removed from the last station and could not be filled completely.

	class Workstation : public Station { //each workstation is-a-kind-of station.
		std::deque<CustomerOrder> m_orders; //These are orders that have been placed on this station to receive service (or already received service).
		Workstation* m_pNextStation = nullptr; //a pointer to the next Workstation on the assembly line.

	public:
		//default constructor
		Workstation() = default;
		//argument Constructor
		Workstation(const std::string& src) : Station(src) {}; //receives a reference to an unmodifiable reference to std::string and passes it to the Station base class.

		void fill(std::ostream& os); //this modifier fills the order at the front of the queue if there are CustomerOrders in the queue; otherwise, does nothing.
		void setNextStation(Workstation* station); // this modifier stores the address of the referenced Workstation object in the pointer to the m_pNextStation. Parameter defaults to nullptr/

		bool attemptToMoveOrder(); //attempts to move the order at the front of the que to the next station in the assembly line.

		Workstation* getNextStation()const; // this query returns the address of next Workstation.
		void display(std::ostream& os)const; //this query inserts the name of the item for which the current object is responsible into the ostream.
		
		Workstation& operator+=(CustomerOrder&& newOrder); //moves the customer order referenced in parameter new order to the back of the que.

		//deleted copy constructor and operator
		Workstation(const Workstation& src) = delete;
		Workstation& operator=(const Workstation& other) = delete;

		//deleted move constructor and operator
		Workstation(Workstation&& src) = delete;
		Workstation& operator=(Workstation&& other) = delete;
	};
}
#endif
