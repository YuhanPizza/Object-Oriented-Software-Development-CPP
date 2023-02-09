#include "Toy.h"
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds
{
    Toy::Toy(const string& toy){
        //id
        size_t idx = toy.find(':');
        m_id = stoi(toy.substr(0, idx));
        int start = idx + 1;

        //name
        idx = toy.find(':', start);
        m_name = toy.substr(start , idx - start);
        if (!m_name.empty() && m_name.back() == ' ') m_name.pop_back();
        start = idx + 1;

        //quantity
        idx = toy.find(':', start);
        m_numberOfItems = stoi(toy.substr(start, idx - start));
        start = idx + 1;

        //presyo
        m_price = stod(toy.substr(start));
    }

    void Toy::update(int numItems) { m_numberOfItems = numItems; };

    ostream& operator<<(ostream& os, const Toy& t){
        os.fill(' ');
        os << "Toy" << setw(8); 
        os << t.m_id << ':';
        os << setw(18); os.setf(std::ios::right);
        os << t.m_name;
        os << setw(3);
        os << t.m_numberOfItems << " items";
        os << setw(8);
        os << fixed << std::setprecision(2) << t.m_price << "/item  subtotal:";
        os << setw(7);
        os << t.m_numberOfItems * t.m_price;
        os << " tax:";
        os << setw(6);
        os << (t.m_numberOfItems * t.m_price) * t.HST;
        os << " total:";
        os << setw(7);
        os << ((t.m_numberOfItems * t.m_price) * t.HST) + t.m_numberOfItems * t.m_price << endl;
        return os;
    }

} 