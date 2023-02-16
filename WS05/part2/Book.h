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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "SpellChecker.h"
#include <string>
namespace sdds {
    class Book {
        std::string m_author{""}; //author
        std::string m_title{""}; //title
        std::string m_country{""}; //the country of publication
        std::string m_desc{ "" }; //the description: a short summary of the book
        size_t m_year{ 0u }; //the year of publication
        double m_price{0.0}; //the price of the book
        void fixSpacing(std::string& str); //private member function for fixing leading and trailing spaces
    public:
        //constructors
        Book()= default; //default constructor
        Book(const std::string& strBook);//constructor with arguments

        //query functions
        const std::string& title() const; //returns m_title
        const std::string& country() const; //returns m_country
        const size_t& year() const; //returns m_year
        double& price(); // returns m_price 

        //templated function
        //the function takes an object that is a functor
        template <typename T> //explain in reflection?
        void fixSpelling(T& spellChecker) { // his function calls the overloaded operator() in spellchecker module passing to it the book description;
            spellChecker(m_desc); //overloaded `()` operator function call from the functor
        }
        friend std::ostream& operator<<(std::ostream& os, const Book& b); //friend outputstream overloaded extraction operator
    };
}

#endif
