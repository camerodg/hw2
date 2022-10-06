#include "book.h"
#include "util.h"
#include <iomanip>
Book::Book(std::string category, const std::string name, const std::string author, const std::string isbn, double price, int qty)
: Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
	 std::string keyword = name_ + "\n" + author_ + "\n" + isbn_;
  return parseStringToWords(keyword);
}

std::string Book::displayString()const
{
	return category_ + "\n" + name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
	
		
}

void Book::dump(std::ostream &os)
{
	Product::dump(os);
	os << isbn_ << "\n" << author_ << "\n";
}

std::string Book::getAuthor()
{
	return author_;
}

std::string Book::getISBN()
{
	return isbn_;
}

void Book::setISBN(std::string isbn)
{
	isbn_ = isbn;
}

void Book::setAuthor(std::string author)
{
		author_=author;
}