#include "Book.h"
#include <sstream>

namespace sdds {

    Book::Book(): m_year(0), m_price(0.0){}
    const std::string& Book::title() const{
        return m_title;
    }
    const std::string& Book::country() const{
        return m_country;
    }
    const size_t& Book::year() const{
        return m_year;
    }
    double& Book::price(){
        return m_price;
    }

    Book::Book(const std::string& strBook): m_year(0), m_price(0.0){
        std::string temp = strBook;
        size_t next_pos = 0;
        size_t pos = temp.find(',');
        m_author = temp.substr(next_pos, pos - next_pos);
        m_author.erase(0, m_author.find_first_not_of(" "));
        m_author.erase(m_author.find_last_not_of(" ") + 1);
        next_pos = pos + 1;
        pos = temp.find(',', next_pos);
        m_title = temp.substr(next_pos, pos - next_pos);
        m_title.erase(0, m_title.find_first_not_of(" "));
        m_title.erase(m_title.find_last_not_of(" ") + 1);
        next_pos = pos + 1;
        pos = temp.find(',', next_pos);
        m_country = temp.substr(next_pos, pos - next_pos);
        m_country.erase(0, m_country.find_first_not_of(" "));
        m_country.erase(m_country.find_last_not_of(" ") + 1);
        next_pos = pos + 1;
        pos = temp.find(',', next_pos);
        m_price = std::stod(temp.substr(next_pos, pos - next_pos));
        next_pos = pos + 1;
        pos = temp.find(',', next_pos);
        m_year = std::stoi(temp.substr(next_pos, pos - next_pos));
        next_pos = pos + 1;
        m_desc = temp.substr(next_pos);
        m_desc.erase(0, m_desc.find_first_not_of(" "));
        m_desc.erase(m_desc.find_last_not_of(" ") + 1);
    }

    std::ostream& operator<<(std::ostream& os, const Book& b){
        os << std::setw(20) << std::right << b.m_author
            << " | " << std::setw(22) << std::right << b.m_title
            << " | " << std::setw(5) << std::right << b.m_country
            << " | " << std::setw(4) << std::right << b.m_year
            << " | " << std::setw(6) << std::fixed << std::setprecision(2) << std::right << b.m_price
            << " | " << std::left<<b.m_desc;
        return os;
    }

}