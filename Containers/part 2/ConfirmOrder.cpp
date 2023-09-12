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
			if (src.m_size != 0) {
				delete[] m_toys;
				m_toys = new const Toy * [src.m_size];
				for (size_t i = 0; i < src.m_size; i++) {
					m_toys[i] = src.m_toys[i];
				}
				m_size = src.m_size;
			}
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
		for (size_t i = 0; i < m_size; i++) {
			if (&toy == m_toys[i]) {
				return *this;
			}
		}
		const Toy** temps = new const Toy * [m_size + 1];
		for (size_t i = 0; i < m_size; i++) {
			temps[i] = m_toys[i];
		}
		delete[] m_toys;
		temps[m_size] = &toy;
		m_toys = temps;
		m_size++;
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		for (size_t i = 0; i < m_size; i++) {
			if (m_toys[i] == &toy) { //loops through all toy pointers inside of array
				for (size_t j = i; j < m_size - 1; j++) { //if a similiar toy is found store that index into value j 
					m_toys[j] = m_toys[j + 1]; //shift all remaining values to the left effectivley making the found index the last member 
				}
				m_size--; // decrements m_size value
				m_toys[m_size] = nullptr; //makes the last member into a nullptr.
				return *this; //made this so it doesnt unecessarily loop 
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