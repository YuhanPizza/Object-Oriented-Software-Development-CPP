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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <vector>
#include <string>
namespace sdds{
    enum{SIZE=6}; //SIZE OF STUFF ya know?
    //functor
class SpellChecker {
    std::string m_badWords[SIZE]{}; //array of bad words retrieved from words.txt
    std::string m_goodWords[SIZE]{}; //array of good words retrieved from words.txt (used to replace bad words)
    size_t m_replacements[SIZE]{}; // counts of replacements for each bad word for instance how many times index 0(teh)occured in the description and were replaced with good words 
public:
    SpellChecker(const char* filename); //constructor
    void operator()(std::string& text);  //overloaded set operator making this object a functor 
    void showStatistics(std::ostream& out) const; //display

};
}
#endif
