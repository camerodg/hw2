#include "book.h"
Book::Book(const std::string name, double price, int qty, const std::string category, const std::string isbn, const std::string author)
: Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

std::set<std::string> Book::keywords() const
{
	 std::string keyword = name_ + "\n" + author_ + "\n" + isbn_;
  return parseStringToWords(keyword);
}

std::string Book::displayString()const
{
	return "book\n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + "\n" + isbn_
		+ "\n" +author_+"\n";	
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