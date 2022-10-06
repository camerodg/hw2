#include "clothing.h"
#include <iomanip>
#include "util.h"
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand)
  : Product(category, name, price, qty) 
{
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const 
{
  std::string keyword = name_ + "\n" + size_ + "\n" + brand_;
  return parseStringToWords(keyword);
}

std::string Clothing::displayString() const
{
  
	return category_ + "\n" + name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";


}
void Clothing::dump(std::ostream& os)
{
		Product::dump(os);
		os << size_ << "\n" << brand_ << "\n";
}
std::string Clothing::getSize()
{
	return size_;
}
std::string Clothing::getBrand()
{
	return brand_;
}
void Clothing::setSize(std::string size)
{
	size_ = size;
}
void Clothing::setBrand(std::string brand)
{
	brand_ = brand;
}