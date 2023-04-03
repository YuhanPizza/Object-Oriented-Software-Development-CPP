#include "Database.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds {
	std::shared_ptr<Database> Database::instance = nullptr;

	Database::Database(const string& filename) {
		cout << this << " Database(const std::string&)" << endl;
		m_file = filename;
		m_count = 0u;

		std::ifstream ifs(filename);

		for (auto i = 0; i < 20 && ifs.good(); i++) {
			getline(ifs, m_keys[i], ' ');
			getline(ifs, m_values[i], '\n');
			m_values[i].erase(0, m_values[i].find_first_not_of(' '));
			replace(m_keys[i].begin(), m_keys[i].end(), '_', ' ');
			m_count++;
		}
		ifs.close();
	}
	shared_ptr<Database> Database::getInstance(const string& filename) {
		if (instance == nullptr) {
			instance = shared_ptr<Database>(new Database(filename));
		}
		return instance;
	}

	Err_Status Database::GetValue(const string& key, string& value)const {
		for (auto i = 0u; i < m_count; i++) {
			if (m_keys[i] == key) {
				value = m_values[i];
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;
	}

	Err_Status Database::SetValue(const string& key, const string& value) {
		if (m_count >= 20) {
			return Err_Status::Err_OutOfMemory;
		}
		m_keys[m_count] = key;
		m_values[m_count] = value;
		m_count++;

		return Err_Status::Err_Success;
	}
	void Database::createBackup()const {
		ofstream ofs(m_file + ".bkp.txt");
		for (auto i = 0u; i < m_count; i++) {
			ofs << setw(25) << left << m_keys[i];
			ofs << "-> " << m_values[i] << endl;
		}
		ofs.close();
	}
	Database::~Database(){
		cout << this << "~Database()" << endl;
		createBackup();
	}
}