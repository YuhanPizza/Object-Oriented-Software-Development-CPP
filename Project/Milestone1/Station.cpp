/*
*****************************************************************************
            Milestone - #1
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Station.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
    size_t Station::m_widthField = 0u;
    int Station::id_generator = 0;
    Station::Station(const string& record) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;
        string description;
        m_id = ++id_generator;

        m_name = util.extractToken(record, next_pos, more);
        m_serialNumber = stoi(util.extractToken(record, next_pos, more));
        m_quantity = stoul(util.extractToken(record, next_pos, more));


        //clean up spaces. or we can alter extractToken function to fix it.
        description = record.substr(next_pos);
        description = description.erase(0, description.find_first_not_of(' '));
        description = description.erase(description.find_last_not_of(' ') + 1);
        m_desc = description;

        m_widthField = max(m_widthField, util.getFieldWidth());
    }

    const string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_quantity;
    }

    void Station::updateQuantity() {
        if (m_quantity > 0) {
            m_quantity--;
        }
    }

    void Station::display(ostream& os, bool full) const {
        os << right <<setw(3) << setfill('0') << m_id << " | "<< setfill(' ');
        os << setw(m_widthField) << left << m_name << " | ";
        os <<right << setw(6) << setfill('0') << m_serialNumber << " | ";
        if (full) {
            os << right <<setw(4) << setfill(' ') << m_quantity << " | ";
            os << left << m_desc;
        }
        os << endl;
    }
}