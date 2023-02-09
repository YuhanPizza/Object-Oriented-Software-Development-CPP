#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>

namespace sdds
{
    class Toy
    {
    private:
        size_t m_id{};
        std::string m_name{"\0"};
        size_t m_numberOfItems{};
        double m_price{0.0};
        const double HST = 0.13;

    public:
        Toy() = default;
        Toy(const std::string& toy);
        void update(int numItems);
        friend std::ostream& operator<<(std::ostream& os, const Toy& t);
    };
} // namespace sdds

#endif

