#include "CustomerOrder.h"
#include <iomanip>
#include <algorithm>


using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 1;

	//constructor
	CustomerOrder::CustomerOrder(const string& src) {
		Utilities util;
		size_t nxtpos = 0u;
		bool more = true;
		string str = src;
		if (str.find_first_not_of(' ') == string::npos) { //life is hard 
			return; // Do nothing
		}
			m_name = util.extractToken(src, nxtpos, more);
			m_product = util.extractToken(src, nxtpos, more);
			m_count = count(src.begin(), src.end(), util.getDelimiter()) - 1;
		if (m_count) {
			//m_item size
			m_items = new Item * [m_count + 1];
			// the array 
			for (auto i = 0u; i < m_count && more; i++) {
				string item_name = util.extractToken(src, nxtpos, more);
				m_items[i] = new Item(item_name);
			}
			if (util.getFieldWidth() > m_widthField) {
				m_widthField = util.getFieldWidth();
			}
		}
	}

	//copy constructor
	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
		throw string("Copy Constructor is not allowed.");
	}

	//MOVE CONSTRUCTOR
	CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept {
		*this = move(src);
	}

	// Move assignment operator
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		if (this != &other) {
			if (other.m_items != nullptr) {
				if (m_items) {
					for (auto i = 0u; i < m_count; ++i)
						delete m_items[i];

					delete[] m_items;
				}
				m_name = other.m_name;
				m_product = other.m_product;
				m_count = other.m_count;
				m_items = other.m_items;

				// reset other object
				other.m_name = "";
				other.m_product = "";
				other.m_count = 0u;
				other.m_items = nullptr;
			}
		}
		return *this;
	}

	//Destructor
	CustomerOrder::~CustomerOrder() {
		if (m_items) {
			for (auto i = 0u; i < m_count; i++) {
				delete m_items[i];
			}
			delete[] m_items;
			m_items = nullptr;
		}
	}

	// Check if all items in the order have been filled
	bool CustomerOrder::isOrderFilled()const {
		for (auto i = 0u; i < m_count; i++) {
			if (m_items[i]->m_isFilled == false) {
				return false;
			}
		}
		return true;
	}
	// Check if all items with the specified itemName have been filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (auto i = 0u; i < m_count; i++) {
			if (m_items[i]->m_itemName == itemName){
				if (m_items[i]->m_isFilled == false) {
					return false;
				}
			}
		}
		return true;
	}


	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (auto i = 0u; i < m_count; ++i) {
			if (m_items[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() != 0 ) {
					station.updateQuantity();
					m_items[i]->m_isFilled = true;
					m_items[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled ";
					os << m_name << ", " << m_product << " [" << m_items[i]->m_itemName << "]" << endl;
				}
				else {
					os << "    Unable to fill ";
					os << m_name << ", " << m_product << " [" << m_items[i]->m_itemName << "]" << endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;

		for (auto i = 0u; i < m_count; ++i) {
			os << "[" << right << setw(6) << setfill('0') << m_items[i]->m_serialNumber << "] ";
			os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_items[i]->m_itemName;
			os << " - " << (m_items[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
		}
	}
}