#include "movie.h"
#include "util.h"
#include <iomanip>
Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating)
: Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}
Movie::~Movie()
{
	
}
std::set<std::string> Movie::keywords() const
{

	std::string keyword = name_ + "\n" + genre_ + "\n" + rating_;
  return parseStringToWords(keyword);
}
std::string Movie::displayString() const
{
		return category_ + "\n" + name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}
void Movie::dump(std::ostream& os)
	{
		Product::dump(os);
		os << genre_ << "\n" << rating_ << "\n";
	}
  std::string Movie::getGenre()
	{
		return genre_;
	}
	std::string Movie::getRating()
	{
		return rating_;
	}
	void Movie::setRating(std::string rating)
	{
		rating_ = rating;
	}
	void Movie::setGenre(std::string genre)
	{
		genre_ = genre;
	}
	