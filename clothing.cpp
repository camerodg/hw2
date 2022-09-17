#include "clothing.h"
Clothing::Clothing(const std::string name, double price, int qty, const  std::string size, const  std::string brand)
: Product("clothing", name, price, qty)
{ 
     brand_ = brand;
		 size_ = size;
}

std::set< std::string>Clothing::keywords() const
{
  //Creates key set that first stores brand 
	//Grabs string of the brand 
	//Returns set with all the keywords for the item 
    std::set< std::string>key = parseStringToWords(brand_);
		key.insert(brand_);
		std::set< std::string>names = parseStringToWords(name_);
		key.insert(names.begin(),names.end());
		return key;
}
std::string Clothing::displayString() const
{
  
	return "clothing\n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + "\n" + size_
	+ "\n" + brand_ +"/n";

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