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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds{
    class Movie { //M = Movie not to be confused with m = member 
        std::string M_title{ "" }; //title
        size_t M_year{ 0u }; //year of release 
        std::string M_description{ "" }; //the description
        void fixSpacing(std::string& str); //private member function to fix leading and trailing spaces
    public:
        //constructor
        Movie() = default; //set to default
        Movie(const std::string& strMovie); //constructor with arguments
        const std::string& title() const; //query

        template <typename T> //templated function 
        void fixSpelling(T& spellChecker) { // his function calls the overloaded operator() in spellchecker module;
            spellChecker(M_title); //passing movie title to the overloaded set operator of spellchecker functor
            spellChecker(M_description); //passing movie description to the overloaded Set operator of spellchecker functor
        }

        friend std::ostream& operator<<(std::ostream& os, const Movie& movie); //friend ostream overloaded extraction operator for displaying 
    };
}
#endif
