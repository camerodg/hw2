#ifndef BOOK_H
#define BOOK_H
#include "util.h"
#include <string>
#include <iostream>
#include "product.h"
class Book: public Product {
	public: 
Book(std::string category, const std::string name, const std::string author, const std::string isbn, double price, int qty);
	~Book();
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os);
  std::string getISBN();
	std::string getAuthor();
	void setISBN(std::string isbn);
	void setAuthor(std::string author);
	private:
	std::string isbn_;
	std::string author_;
};
#endif