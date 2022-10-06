#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "user.h"
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>

class MyDataStore : public DataStore
{
	public:
   MyDataStore();
	 ~MyDataStore();
	 void addProduct(Product* p);
	 void addUser(User* u);
	 void addToCart(std::string username, Product* p);
	 void buyCart(std::string username);
	 User* getUser(std::string username);
	 std::vector<Product*> search(std::vector<std::string>& terms, int type);
	 void viewCart(std::string username);
	 void dump(std::ostream& ofile);

	 private:
	//resizeable data structrues to hold the products and the users 
	//that will be stored in the databases 
	std::map<std::string, User*> users;
  std::map<std::string, Product*> products;
	//map will have the user as the key and then all the products 
	//in their cart as the values that are queues to satisfy the FIFO requirement 
	std::map<User*, std::vector<Product*>> carts;
	//stores all the one letter words and map them to product pointers 
	std::map<std::string,std::set<Product*>> termProd;	



};
#endif

