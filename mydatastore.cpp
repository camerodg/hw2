#include "datastore.h"
#include "util.h"
#include "user.h"
#include "mydatastore.h"
#include "product.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
MyDataStore::MyDataStore(){}
MyDataStore::~MyDataStore()
{
	//deletes all the users 
	users.clear();

	//delete all the products
	products.clear();
}
//Adds user to the database
//the vector holding all the users 
void MyDataStore::addUser(User* u)
{
  if(u == nullptr)
  {
  	std::cout << "Invalid user input" << std::endl;
  	return;
  }

  //Insert user into the database of users 
  users.insert(make_pair(u->getName(),u));

  //Insert user into the cart database with a empty cart 
  //std::vector<*Product> cart;
  carts[u];
}

//Adds product to the database
//the vector holding all the products 
void MyDataStore::addProduct(Product* p)
{
	if(p == nullptr)
	{
		std::cout << "Invalid product input" << std::endl;
		return;
	}

	std::set<std::string>singleWord = p->keywords();
	for(std::set<std::string>::iterator it1 = singleWord.begin(); it1 != singleWord.end(); ++it1)
	{
		if(termProd.find(*it1) == termProd.end())
		{
			std::set<Product*> prod;
			prod.insert(p);
			termProd.insert({*it1,prod});
		}

		else
		{
	    termProd.find(*it1)->second.insert(p);
		}
	}
	products.insert(make_pair(p->getName(),p));
}

//Find the corresponding username within the database
//and add the product to that username 
void MyDataStore::addToCart(std::string username, Product* p)
{

	    /*Product will be stored with the corresponding username 
	    find the username and store the product with the user
      within the cart database
      */
			if(users.find(username) != users.end())
			{
				User* temp = users[username];
			
	    if(carts.find(temp) != carts.end())
	    {
	       carts[temp].push_back(p);
	    }
			}
	    else
	    {
	    	 std::cout << "Invalid Request" << std::endl;
	    }
}

void MyDataStore::viewCart(std::string username)
{
	User* u = nullptr;
	//find the username within the carts database first
	if(users.find(username) != users.end())
	{
		 u = users[username];
	}
	//find the username within the cart database with the users and their products
	if(carts.find(u) != carts.end())
	{
		std::cout << "Invalid User Input" << std::endl;
	}
  //make iterator that point to the user's cart 
  for(std::map<User*, std::vector<Product*>>::iterator currUser = carts.begin(); currUser != carts.end(); ++currUser)
  {
  	//grab the size of the user's cart
  	int size = currUser->second.size();
    
    //iterate through and print out the current item's name
  	for(int i = 0; i < size; i++)
  		{
  			std::cout << currUser->second[i]->displayString() << std::endl;
  		}

  }
}


void MyDataStore::dump(std::ostream& ofile)
{	
	ofile<<"<products>"<<"\n";
	//print out all the products 
	for(std::map<std::string, Product*>::iterator it1 = products.begin(); it1 != products.end();++it1)
	{
		it1->second->dump(ofile);
	}
	//print out all the users 
	ofile <<"</products>"<<"\n"<<"<users>"<<"\n";
	for(std::map<std::string, User*>::iterator it2 = users.begin();it2!=users.end();++it2)
	{
		(it2->second)->dump(ofile);
	}
	ofile<<"</users>"<<std::endl;

}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{

//create a map that stores all the keywords into a
std::vector<Product*> results;
std::set<Product*> temp;
std::set<Product*> temp1 = (termProd.find(terms[0])->second);
temp = setIntersection(temp,temp1);

for(size_t i = 0; i < terms.size(); i++)
{
	if(type == 0)
	{
		temp = setIntersection(temp,(termProd.find(terms[i])->second));
	}

	else if(type == 1)
	{
		temp = setUnion(temp,(termProd.find(terms[i])->second));
	}
}

for(std::set<Product*>::iterator it1 = temp.begin(); it1 != temp.begin(); ++it1)
{
	results.push_back(*it1);
}
 return results;
}

/* Iterates through user's cart within the map
   If in stock and the user credit > balance
   remove the item from the cart, reduce the qty of the item by 1
   reduce the user's credit with each purchase 
   if not enough funds, do nothing
   */
void MyDataStore::buyCart(std::string username)
{
  //look in the users database to see if the user even exists 
	if(users.find(username) == users.end())
	{
		std::cout << "Invalid Username" << std::endl;
		return;
	}
   //Goal:: grab the username to ->towards User object
	 //then have the User object -> cart of products 
	 //then buy them   

   //pointer to a user object 
	 User* currUser = users[username];
	 std::vector<Product*> userProd = carts[currUser];
	 //std::vector<Product*> final = userProd;
      //iterate through the products in the cart and buy them one by one 
     for(std::vector<Product*>::iterator it3 = userProd.begin(); it3 != userProd.end(); ++it3)
      {
      	/*look at the current quantity of the current item to
      	see if the item is still in stock and look the balance to
      	see if the user has enough money to buy the products 
      	if so, the deduct the user's balance, deduct the quantity by one
      	and get the item out of the cart of the user 
      	*/
      	if(((*it3)->getQty() > 0) && (currUser->getBalance() >= (*it3)->getPrice()))
      	{
      		std::cout << "Thank you for your purchase. The user has bought " << (*it3)->getName() << std::endl;
      		double newBalance = currUser->getBalance() - (*it3)->getPrice();
      		std::cout << "The new balance is " << newBalance << std::endl;
      		if(newBalance >= 0)
      		{
      			(*it3)->subtractQty(1);
						double priceProd = (*it3)->getPrice();
      			currUser->deductAmount(priceProd);
      			//need to delete the item out of the cart 
						//final = (userProd.begin(),userProd.end(),it3);
						//users[username].erase (it3);
						//userProd.erase(std::remove(userProd.begin(),userProd.end(),it3));
						userProd.erase(it3);
            
      		}
      	//	it3++;
      	}

      	else
      	{
					std::cout << "Not enough funds for this product" << std::endl;
      		continue;
      	}
				
      }
   }

	 User* MyDataStore::getUser(std::string username)
	 {
		 if(users.find(username) != users.end())
		 {
			 return users[username];
		 }
		 return 0;
	 }
