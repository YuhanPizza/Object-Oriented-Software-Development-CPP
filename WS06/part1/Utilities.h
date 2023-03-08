#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"
#include "Employee.h"
#include <sstream>

namespace sdds {
    Person* buildInstance(std::istream& in) {
        std::string tag;
        std::string line;
        std::getline(in, line);

        if (!line.empty()) {
            std::stringstream ss(line);
            getline(ss, tag, ',');
            if (tag[0] == 'e' || tag[0] == 'E') {
                return new Employee(ss);
            }
        }

        return nullptr;
    }
}
#endif