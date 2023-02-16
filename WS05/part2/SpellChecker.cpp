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

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds{
    SpellChecker::SpellChecker(const char* filename) {
        // initialize the badWords and goodWords arrays from file
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw "Bad file name!"; //if file is not open throws an exception of type const char
        }
        std::string line;
        size_t count{ 0u };
        size_t space{ 0u };
        while (std::getline(file, line)) { 
            line.erase(0, line.find_first_not_of(' '));
            space = line.find(' ');
            m_badWords[count] = line.substr(0, space);
            line.erase(0, space);

            line.erase(0, line.find_first_not_of(' '));
            space = line.find(' ');
            m_goodWords[count] = line.substr(0, space);
            ++count;
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for (auto i = 0; i < SIZE; ++i) {
                    //finds bad words loops for teh first until no teh is found then the next one etc...
            while (text.find(m_badWords[i]) != std::string::npos) { //explain usage for reflection? string::npos = no-position, it is usually used to indicate 
                text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]); // that no matches were found in the string. Thus, if it returns true, 
                ++m_replacements[i];                                                          // matches were found at no positions (i.e., no matches).
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const { //display for replacements
        out << "Spellchecker Statistics" << std::endl;
        for (size_t i = 0; i < SIZE; ++i) {
            out << std::right << std::setw(15) << m_badWords[i] << ": " //m_badWords 6 indexes in total
                << m_replacements[i] << " replacements" << std::endl; //shows the number of replacements done per bad word 
        }
    }
}