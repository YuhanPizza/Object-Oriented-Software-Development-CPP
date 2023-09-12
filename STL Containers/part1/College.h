#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include "Person.h"

namespace sdds {
	class College {
		std::vector<Person*> m_persons;
	public:
		College(const College&) = delete;
		College& operator=(const College&) = delete;

		College() = default;
		~College();

		College& operator+=(Person* thePerson);
		void display(std::ostream& out) const;
	};
}
#endif
