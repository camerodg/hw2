#include "movie.h"
Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating)
: Product("movie",name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}
	std::set<std::string> Movie::keywords() const
	{
		//Creates key set that first stores genre 
	//Grabs string of the name 
	//Returns set with all the keywords for the item
		std::set<std::string>key = parseStringToWords(genre_);
		key.insert(genre_);
		std::set<std::string>name = parseStringToWords(name_);
		key.insert(name.begin(),name.end());
		return key;
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
	