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
#include "Toy.h"
#include <iomanip>

using namespace std;
namespace sdds{
    Toy::Toy(const string& toy){
        //idx is a unsinged int that stores the index

        //id
        size_t idx = toy.find(':');
        m_id = stoul(toy.substr(0, idx));//stores the value of index 0 to the index location of ':' to the m_id (stoul is string to unsigned intiger )
        size_t start = idx + 1; //we move the index by 1 soo we go on to the next XD

        //name
        idx = toy.find(':', start);
        m_name = toy.substr(start , idx - start);
        //if (!m_name.empty() && m_name.back() == ' ') m_name.pop_back(); //made a conditional to remove a space at the end of the string 
        m_name.erase(m_name.find_last_not_of(' ') + 1); // last not of will return the index of the last not space value and + 1 so it gets erased by str.erase
        start = idx + 1;

        //quantity
        idx = toy.find(':', start);
        m_numberOfItems = stoul(toy.substr(start, idx - start));
        start = idx + 1;

        //presyo
        m_price = stod(toy.substr(start));
    }

    void Toy::update(int numItems) { m_numberOfItems = numItems; }; // super tiny lul 

    ostream& operator<<(ostream& os, const Toy& t){
        //----local function variables----
        double subTotal {0.0}, tax{0.0}, total{0.0};
        subTotal = t.m_numberOfItems * t.m_price;
        tax = subTotal * t.HST;
        total = tax + subTotal;
        //--------------------------------
        os.fill(' ');
        os << "Toy" << setw(8); 
        os << t.m_id << ':';
        os << setw(18); os.setf(ios::right);
        os << t.m_name;
        os << setw(3);
        os << t.m_numberOfItems << " items";
        os << setw(8);
        os << fixed << std::setprecision(2) << t.m_price << "/item  subtotal:";
        os << setw(7);
        //os << t.m_numberOfItems * t.m_price; //subTotal optional usage
        os << subTotal;
        os << " tax:";
        os << setw(6);
        //os << (t.m_numberOfItems * t.m_price) * t.HST; //tax optional usage 
        os << tax;
        os << " total:";
        os << setw(7);
        //os << ((t.m_numberOfItems * t.m_price) * t.HST) + t.m_numberOfItems * t.m_price << endl; //total optional usage
        os << total << endl;
        return os;
    }

} 