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
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>

namespace sdds{
    class Toy{
        size_t m_id{ 0u }; //id
        std::string m_name{"\0"}; //name
        size_t m_numberOfItems{ 0u }; //quantity
        double m_price{0.0}; //presyo
        const double HST = 0.13; //tax percentage 
    public:
        Toy() = default; //default constructor
        Toy(const std::string& toy); //constructor
        void update(int numItems); //update function
        friend std::ostream& operator<<(std::ostream& os, const Toy& t); //ostream extraction operator (friend)
    };
}

#endif

