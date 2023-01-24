/*
*****************************************************************************
			Workshop - #2
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <chrono>
#include <string>

namespace sdds {
	class TimedTask {
		enum { MAX_NUMBER = 10 };
		size_t t_current{ 0u };

		std::chrono::steady_clock::time_point t_startTime;
		std::chrono::steady_clock::time_point t_endTime;

		struct Task {
			std::string t_name;
			std::string t_uTime;
			std::chrono::steady_clock::duration t_durTask;
			Task() : t_name(""), t_uTime("") {}; //constructor
		} t_task[MAX_NUMBER];

	public:
		TimedTask() {};

		void startClock();
		void stopClock();

		void addTask(const char* org);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& org);
	};
}

#endif
