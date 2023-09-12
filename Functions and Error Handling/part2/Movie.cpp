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

#include <iostream>
#include "Movie.h"
#include <iomanip>
namespace sdds {
    const std::string& Movie::title() const { //returns the Movie title
        return M_title;
    }

    Movie::Movie(const std::string& strMovie) {
        if (!strMovie.empty()) { //making sure its not empty
            std::string delimiter = ","; //setting up delimiter
            std::size_t next_pos = 0; //position index
            std::size_t pos = strMovie.find(delimiter); //positiong of first ','

            //title
            M_title = strMovie.substr(next_pos, pos); //stores from the index 0 of the string "strMovie" to the position of the first delimiter to member attribute M_title
            fixSpacing(M_title); //function to clean up leading and trailing spaces
            next_pos = pos + 1;

            //year 
            pos = strMovie.find(delimiter, next_pos);
            M_year = std::stoi(strMovie.substr(next_pos, pos - next_pos)); //string to int
            next_pos = pos + 1;

            //description
            M_description = strMovie.substr(next_pos);
            fixSpacing(M_description);
        }
    }
    //private member function for cleaning up leading and trailing spaces
    void Movie::fixSpacing(std::string& str) {
        str.erase(0, str.find_first_not_of(" ")); //erase leading spaces from index 0 of the string to the first not of space
        str.erase(str.find_last_not_of(" ") + 1); //erase trailing spaces +1 from the location of last not space
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) { //format for ostream 
        os << std::right << std::setw(40) << movie.M_title
            << " | " << std::left << std::setw(4) << movie.M_year
            << " | " << movie.M_description << std::endl;
        return os;
    }
    
};