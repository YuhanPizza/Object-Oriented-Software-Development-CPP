/*
*****************************************************************************
            Workshop - #6
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Utilities.h"
#include <iostream>
#include <sstream>

namespace sdds {
	Person* buildInstance(std::istream& in) {
        std::string tag; //used for the tag on which object it belongs
        std::string line; //stores in the istream object
        std::getline(in, line); 

        if (!line.empty()) {
            std::istringstream ss(line); // stores that string into a string stream object
            getline(ss, tag, ','); //extracts a string from the ss object till the delimiter
            switch (tag[0]) { //based on the value of string it goes to a certain case.
            case 'e':
            case 'E':
                return new Employee(ss);//calls its constructor
            case 'p':
            case 'P':
                return new Professor(ss);
            case 's':
            case 'S':
                return new Student(ss);
            default:
                break;
            }
        }

        return nullptr;
    }
}