/*
*****************************************************************************
			Workshop - #4
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "ConfirmOrder.h"
using namespace std;
namespace sdds {
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& src) {
		*this = src;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src) {
		if (this != &src) {
			delete[] m_toys;
			m_toys = new const Toy * [src.m_size];
			for (size_t i = 0; i < src.m_size; i++) {
				m_toys[i] = src.m_toys[i];
			}
			m_size = src.m_size;
		}
		return *this;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& src) noexcept{
		*this=move(src);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src) noexcept{
		if (this != &src) {
			delete[] m_toys;
			m_toys = src.m_toys;
			src.m_toys = nullptr;
			m_size = src.m_size;
			src.m_size = 0;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool found = false;
		for (size_t i = 0; i < m_size; i++) {
			if (&toy == m_toys[i]) {
				found = true;
			}
		}
		if (!found) {
			const Toy** temps = new const Toy * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temps[i] = m_toys[i];
			}
			delete[] m_toys;
			m_toys = temps;
			temps[m_size] = &toy;
			m_size++;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		for (size_t i = 0; i < 5; i++) {
			if (&toy == m_toys[i]) {
				m_toys[i] = nullptr;
				m_size--;
			}
		}
		return *this;
	}
	ConfirmOrder::~ConfirmOrder() {
		delete[] m_toys;
	}
	ostream& operator<<(ostream& os, const ConfirmOrder& src) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (src.m_size == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (size_t i = 0; i < src.m_size; i++) {
				os << *src.m_toys[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}