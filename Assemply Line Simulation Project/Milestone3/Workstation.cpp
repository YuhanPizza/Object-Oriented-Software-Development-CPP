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
#include "Workstation.h"
namespace sdds {
	//global variables
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	void Workstation::fill(std::ostream& os){
		if (m_orders.empty()) {
			return;
		}
		m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder(){ //if an order has been moved, return true; false otherwise.
		//if the order requires no more service at this station or cannot be filled (not enough inventory), move it to the next station; otherwise do nothing
		if (m_orders.empty()) {
			return false;
		}
		if (m_orders.front().isItemFilled(getItemName())) {
			if (m_pNextStation) {
				*m_pNextStation += std::move(m_orders.front());
			}
			// if there is no next station in the assembly line, then the order is moved into g_completed or g_incomplete queue
			else if (!m_orders.front().isOrderFilled()) {
				g_incomplete.push_back(std::move(m_orders.front()));
			}
			else {
				g_completed.push_back(std::move(m_orders.front()));
			}
			m_orders.pop_front();
		}
		else if (this->getQuantity() <= 0) {
			if (m_pNextStation) {
				*m_pNextStation += std::move(m_orders.front());
			}
			else {
				g_incomplete.push_back(std::move(m_orders.front()));
			}
			m_orders.pop_front();
		}
		return true;
	}

	void Workstation::setNextStation(Workstation* station){
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const{
		os << (getNextStation() ? (getItemName() + " --> " + m_pNextStation->getItemName() + "\n") : (getItemName() + " --> End of Line\n"));
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}