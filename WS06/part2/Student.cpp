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
#include "Student.h"
#include <sstream>
#include <iomanip>

using namespace std;

namespace sdds {
	Student::Student(istream& is) : m_courses(nullptr) { //constructor that recieves an istream object
		string name, age, id, count, courses;
		auto removeSpace = [](string& src) { //this lambda is used to clear leading and trailing spaces
			bool exit = false;

			while (!exit) {
				if (src[0] == ' ')
					src.erase(0, src.find_first_not_of(' '));
				else if (src[src.length() - 1] == ' ')
					src.erase(src.find_last_not_of(' ') + 1);
				else
					exit = true;
			}

			return src;
		};
		//i dont think i need to explain this
		getline(is, name, ',');
		m_name = removeSpace(name); //lambda function call
		getline(is, age, ',');
		try { //try-catch to catch errors as requested in workshop requirements?
			m_age = stoul(age); //if this doesnt work
		}
		catch (...) { //gets caught here 
			throw "\n"+m_name + "++Invalid record!"; //throws this string
		}
		getline(is, id, ',');
		id = removeSpace(id);
		if (id.empty() || id[0] != 'S') {
			throw m_name + "++Invalid record!";
		}
		m_id = id;
		getline(is, count, ','); //count determins the size of the m_courses array
		try {
			m_count = stoul(count);
		}
		catch (...) {
			throw m_name + "++Invalid record!";
		}
		getline(is, courses);
		courses = removeSpace(courses);
		istringstream iss(courses); //creats a stringstream object iss from courses
		if (m_courses) {
			delete[]m_courses;
			m_courses = nullptr;
		}
		//creates new m_courses[index]
		m_courses = new string[m_count]; //creates the dynamic array accourding to size
		for (auto i = 0u; i < m_count; i++) {
			getline(iss, m_courses[i], ','); //stores the courses in different indexes
			m_courses[i] = removeSpace(m_courses[i]);
		}
	}
	Student::~Student() { //deletes the courses at the end cuz its a destructor
		delete[]m_courses;
	}
	string Student::status() const{
		return "Student";
	}
	string Student::name() const {
		return m_name;
	}
	string Student::age() const {
		return to_string(m_age);
	}
	string Student::id() const {
		return m_id;
	}
	void Student::display(ostream& out) const {
		out << "| ";
		out << left << setw(10) << "Student"
			<< "| " << left << setw(10) << m_id
			<< "| " << left << setw(20) << m_name
			<< " | " << left << setw(3) << m_age << " |";
		if (m_count > 0) {
			out << m_courses[0];
			for (auto i = 1u; i < m_count; i++) {
				out << ", " << m_courses[i];
			}
		}
	}
}