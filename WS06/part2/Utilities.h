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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

namespace sdds {
    Person* buildInstance(std::istream& in); //gets called in the w6.cpp loadData creates an object 
}
#endif