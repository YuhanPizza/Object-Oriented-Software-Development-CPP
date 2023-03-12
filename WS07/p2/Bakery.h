#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <string>
#include <vector>
#include <algorithm>
#include <list>

namespace sdds {
	enum class BakedType {BREAD,PASTERY};
	struct BakedGood {
		BakedType m_type{};
		std::string m_desc{};
		size_t m_life{0u};
		size_t m_count{0u};
		double m_price{0.0};
	};
	class Bakery {
		std::vector<BakedGood> m_goods;
	public:
		Bakery(const char* filesrc);

		void showGoods(std::ostream& os)const;
		void sortBakery(const std::string& field);
		std::vector<BakedGood> combine(const Bakery& other);
		bool inStock(const std::string& desc, const BakedType& type) const;
		std::list<BakedGood> outOfStock(const BakedType& type) const;
	};
	std::ostream& operator<<(std::ostream& out, const BakedGood& src);
}
#endif
