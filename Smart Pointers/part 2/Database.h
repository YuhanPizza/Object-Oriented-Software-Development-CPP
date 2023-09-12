/*
*****************************************************************************
            Workshop - #8
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#include <string>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

namespace sdds {
    enum class Err_Status {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };
    template<typename T>
    class Database {
        static std::shared_ptr<Database<T>> instance;
        size_t m_count{ 0u };
        std::string m_keys[20];
        T m_values[20];
        std::string m_file;

        //constructor
        Database(const std::string& filename) {
            std::cout << this << " Database(const std::string&)" << std::endl;
            m_file = filename;
            m_count = 0u;

            std::ifstream ifs(filename);

            for (auto i = 0; i < 20 && ifs.good(); i++) {
                getline(ifs, m_keys[i], ' ');
                T value;
                ifs >> value >> std::ws;
                encryptDecrypt(value);
                m_values[i] = value;
                std::replace(m_keys[i].begin(), m_keys[i].end(), '_', ' ');
                m_count++;
            }
            ifs.close();
        }
        void encryptDecrypt(T& value) {};

    public:
        static std::shared_ptr<Database<T>> getInstance(const std::string& filename) {
            if (instance == nullptr) {
                instance = std::shared_ptr<Database<T>>(new Database<T>(filename));
            }
            return instance;
        }

        Err_Status GetValue(const std::string& key, T& value)const {
            for (auto i = 0u; i < m_count; i++) {
                if (m_keys[i] == key) {
                    value = m_values[i];
                    return Err_Status::Err_Success;
                }
            }
            return Err_Status::Err_NotFound;
        }
        Err_Status SetValue(const std::string& key, const T& value) {
            if (m_count >= 20) {
                return Err_Status::Err_OutOfMemory;
            }
            m_keys[m_count] = key;
            m_values[m_count] = value;
            m_count++;

            return Err_Status::Err_Success;
        }
        ~Database() {
            std::cout << this << "~Database()" << std::endl;
            std::ofstream ofs(m_file + ".bkp.txt");
            for (auto i = 0u; i < m_count; i++) {
                ofs << std::setw(25) << std::left << m_keys[i];
                encryptDecrypt(m_values[i]);
                ofs << " -> " << m_values[i] << std::endl;
            }
            ofs.close();
        }
    };

    template<>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[]{ "secret encryption key" };
        for (auto& c : value) {
            for (const auto& k : secret) {
                c ^= k;
            }
        }
    };

    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };
        auto bytes = reinterpret_cast<char*>(&value);
        for (size_t i = 0; i < sizeof(long long); i++) {
            for (const auto& k : secret) {
                bytes[i] ^= k;
            }
        }
    };
    template<typename T>
    std::shared_ptr<Database<T>> Database<T>::instance = nullptr;
}
#endif