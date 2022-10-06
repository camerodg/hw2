#ifndef CLOTHING_H
#define CLOTHING_H
#include "util.h"
#include <string>
#include <iostream>
#include <string> 
#include "product.h"
class Clothing: public Product{
	public: 
	Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
	~Clothing();
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
#endif