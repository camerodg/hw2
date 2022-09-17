#include "product.h"
class Clothing: public Product{
	public: 
	Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand);
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os);
	std::string getBrand();
	void setBrand(std::string brand);
	std::string getSize();
	void setSize(std::string size);
	private:
	std::string brand_;
	std::string size_;
};