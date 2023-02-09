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

#include "Child.h"

using namespace std;

namespace sdds {
    Child::Child(string g_name, size_t g_age, const Toy* toys[], size_t count) : m_cName(g_name), m_age(g_age), m_tCount(count) { //assigns parameter inputs to member variables
        if (count > 0) {
            m_toys = new const Toy * [count]; //creates an new pointer array of Toy object pointers
            for (size_t i = 0; i < count; i++) { //handles the creation of new m_toys
                m_toys[i] = new Toy{ *toys[i] }; //his code creates a new pointer to a "Toy" object by using the new operator.
                // pointer to the new Toy object is then stored in the m_toys array at index i.
            }
        }
    }


    Child::Child(const Child& src) { //child copy constructor
        *this = src; //calls the copy assignment operator
    }

    // Copy Assignment Operator
    Child& Child::operator=(const Child& src) { //copy assignment operator
        if (this != &src) { //if it is not a copy of itself
            if (m_toys) { //if toy is not in an empty state
                for (size_t i = 0; i < m_tCount; i++) {
                    delete m_toys[i];
                    m_toys[i] = nullptr;
                }
                delete[] m_toys; //delete
                m_toys = nullptr;
            }
            m_cName = src.m_cName; //assigns value given in parameter
            m_age = src.m_age;
            m_tCount = src.m_tCount;
            m_toys = new const Toy * [m_tCount];
            for (size_t i = 0; i < m_tCount; i++) { //individual toy objects inside of toy array
                m_toys[i] = new Toy{ *src.m_toys[i] };
            }
        }
        return *this;
    }

    // Destructor
    Child::~Child() {
        for (size_t i = 0; i < m_tCount; i++) {
            delete m_toys[i];
        }
        delete[] m_toys;
    }

    // Move Constructor
    Child::Child(Child&& src) noexcept{ // no except is used by code that calls the function to make decisions about error handling. 
        *this = move(src);
    }

    // Move Assignment Operator
    Child& Child::operator=(Child&& src) noexcept{ // noexcept signals to the compiler and to other code that the move operation is exception-safe
        if (this != &src) {
            if (m_toys) {
                for (size_t i = 0; i < m_tCount; i++) {
                    delete m_toys[i];
                    m_toys[i] = nullptr;
                }
                delete[] m_toys;
                m_toys = nullptr;
            }
            m_cName = src.m_cName;
            src.m_cName = { '\0' };
            m_age = src.m_age;
            src.m_age = 0u;
            m_tCount = src.m_tCount;
            src.m_tCount = 0u;
            m_toys = src.m_toys; //well see if we need to delete these but i think since its not actually allocating memory there should be no need to?
            src.m_toys = nullptr;
        }
        return *this;
    }

    // size query function
    size_t Child::size() const {
        return m_tCount;
    }

    ostream& operator<<(ostream& os, const Child& src) {
        static size_t CALL_CNT = 1;
        os << "--------------------------" << endl;
        os << "Child " << CALL_CNT << ": ";
        if (!src.m_cName.empty() && src.m_cName.front() != '\0')os << src.m_cName;
        os <<" "<< src.m_age << " years old:" << endl;
        os << "--------------------------" << endl;
        if (src.m_tCount == 0) {
            os << "This child has no toys!" << endl;
        }
        else {
            for (size_t i = 0; i < src.m_tCount; i++) {
                os << *src.m_toys[i]; //this calls the friend extraction operator of the toy class
            }
        }
        os << "--------------------------" << endl;
        CALL_CNT++;
        return os;
    }
}