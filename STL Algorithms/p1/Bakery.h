#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <string>
#include <vector>
#include <algorithm>

namespace sdds {
	enum class BakedType {BREAD,PASTRY};
	struct BakedGood {
		BakedType m_type{};
		std::string m_desc{};
		size_t m_life{0u};
		size_t m_count;
		double m_price;
	};
	class Bakery {
		std::vector<BakedGood> m_goods;
	public:
		Bakery(const char* filesrc);
		void showGoods(std::ostream& os)const;
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& src);
}
#endif
