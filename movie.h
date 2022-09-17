#include "product.h"
class Movie: public Product{
	public: 
	Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating);
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os);
	std::string getGenre();
	void setGenre(std::string genre);
	std::string getRating();
	void setRating(std::string rating);
	private:
	std::string genre_;
	std::string rating_;
};