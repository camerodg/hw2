#include "movie.h"
Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating)
: Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}
	std::set<std::string> Movie::keywords() const
	{

		std::string keyword = name_ + "\n" + genre_ + "\n" + rating_;
    return parseStringToWords(keyword);
	}
	std::string Movie::displayString() const
	{
		return "movie\n" + name_ + "\n" + std::to_string(price_) +
		 "\n" + std::to_string(qty_) + "\n" + genre_ + "\n" + rating_ 
		 + "\n";
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
	