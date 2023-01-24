#include <iostream>
#include <iomanip>
#include "TimedTask.h"

using namespace std;

namespace sdds {
	void TimedTask::startClock() {
		t_startTime = std::chrono::steady_clock::now();
	}
	
	void TimedTask::stopClock() {
		t_endTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* org) {
		if (t_current < MAX_NUMBER) {
			if (org != nullptr || org[0] != '\0') { //check if org has value 
				t_task[t_current].t_name = org;
				t_task[t_current].t_uTime = "nanoseconds";

				//calculates and stores for the durTask
				t_task[t_current].t_durTask = std::chrono::duration_cast<std::chrono::nanoseconds>(t_endTime - t_startTime);

				t_current++;
			}
			else {
				//safe empty state 
				t_task[t_current].t_name = "";
				t_task[t_current].t_uTime = "";
			}
		}
	}
	//fix this by creating helper functions so that you dont need a friend function 
	//but as stated in the workshop it is required
	ostream& operator<<(ostream& os, const TimedTask& org) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;

		for (auto i = 0u; i < org.t_current; i++) {
			os.width(21);
			os.setf(ios::left);
			os << org.t_task[i].t_name;
			os.unsetf(ios::left);
			os.width(13);
			os.setf(ios::right);
			os << org.t_task[i].t_durTask.count();
			os << " " << org.t_task[i].t_uTime << endl;
		}
		return os << "--------------------------" << endl;
	}
}