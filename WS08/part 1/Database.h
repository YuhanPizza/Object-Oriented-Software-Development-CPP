#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#include <string>
#include <memory>

namespace sdds {
	enum class Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	class Database {
		static std::shared_ptr<Database> instance; //store the address
		size_t m_count{ 0u }; //tracks down the number of entries
		std::string m_keys[20]; // A statically-allocated array of strings representing the keys.
		std::string m_values[20]; // A statically-allocated array of strings representing the values
		std::string m_file; //A string representing the database file name
		Database(const std::string& filename);
		void createBackup() const;

	public:
		static std::shared_ptr<Database> getInstance(const std::string& filename);
		Err_Status GetValue(const std::string& key, std::string& value)const;
		Err_Status SetValue(const std::string& key, const std::string& value);
		~Database();
	};
}
#endif
