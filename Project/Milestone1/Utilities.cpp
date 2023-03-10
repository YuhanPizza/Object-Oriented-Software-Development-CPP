/*
*****************************************************************************
            Milestone - #1
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Utilities.h"
#include <stdexcept>

using namespace std;

namespace sdds {
	char Utilities::m_delimiter = '\0';  // initialize delimiter to null character

    void Utilities::setFieldWidth(size_t src) {
        m_widthField = src;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    string Utilities::extractToken(const string& str, size_t& nxt_pos, bool& more) {
        string token;
        size_t delimiter_pos = str.find(m_delimiter, nxt_pos);
        auto removeSpace = [](string& src) {
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
        if (delimiter_pos != std::string::npos) {
            token = str.substr(nxt_pos, delimiter_pos - nxt_pos);
            nxt_pos = delimiter_pos + 1;
            more = true;
        }
        else {
            token = str.substr(nxt_pos);
            nxt_pos = str.length();
            more = false;
        }

        if (token.empty()) {
            more = false;
            throw std::runtime_error("Empty token");
        }

        if (token.length() > m_widthField) {
            setFieldWidth(size_t(token.length()));
        }
        token = removeSpace(token);
        return token;
    }

    void Utilities::setDelimiter(char src) {
        m_delimiter = src;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }

}