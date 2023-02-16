/*
*****************************************************************************
            Workshop - #5
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Book.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    //queries
    const std::string& Book::title() const{ //returns title
        return m_title;
    }
    const std::string& Book::country() const{ //returns country
        return m_country;
    }
    const size_t& Book::year() const{ //returns year
        return m_year;
    }
    double& Book::price(){ //returns price
        return m_price;
    }

    //overloaded constructor
    Book::Book(const std::string& strBook){
        if (!strBook.empty()) { //making sure the string isnt empty
            std::string delimiter = ",";
            size_t next_pos = 0;
            size_t pos = strBook.find(delimiter); //position of the first ',' 

            //gasulat                        
            m_author = strBook.substr(next_pos, pos ); //stores in the author from 0 to the index of the first ','
            fixSpacing(m_author);
            next_pos = pos + 1; //next 

            //titulo
            pos = strBook.find(delimiter, next_pos);//look for this ',', next_post is the index to start looking at returns a size_t value 
            m_title = strBook.substr(next_pos, pos - next_pos);
            fixSpacing(m_title); //called my private member function for erasing spaces
            next_pos = pos + 1;

            //nasud
            pos = strBook.find(delimiter, next_pos);
            m_country = strBook.substr(next_pos, pos - next_pos);
            fixSpacing(m_country);
            next_pos = pos + 1;

            //presyo
            pos = strBook.find(delimiter, next_pos);
            m_price = std::stod(strBook.substr(next_pos, pos - next_pos)); //string to double
            next_pos = pos + 1;

            //tuig
            pos = strBook.find(delimiter, next_pos);
            m_year = std::stoi(strBook.substr(next_pos, pos - next_pos));  //string to intiger
            next_pos = pos + delimiter.length();

            //paghulagway
            m_desc = strBook.substr(next_pos);
            fixSpacing(m_desc);
        }
    }

    std::ostream& operator<<(std::ostream& os, const Book& b){ //just format required 
        os << std::setw(20) << std::right << b.m_author
            << " | " << std::setw(22) << std::right << b.m_title
            << " | " << std::setw(5) << std::right << b.m_country
            << " | " << std::setw(4) << std::right << b.m_year
            << " | " << std::setw(6) << std::fixed << std::setprecision(2) << std::right << b.m_price
            << " | " << std::left<<b.m_desc <<std::endl;
        return os;
    }
    //fix spacing cleaner code (private member function)
    void Book::fixSpacing(std::string& str) {
        str.erase(0, str.find_first_not_of(" ")); //erase leading spaces from index 0 of the string to the first not of space
        str.erase(str.find_last_not_of(" ") + 1); //erase trailing spaces +1 from the location of last not space
    }
}