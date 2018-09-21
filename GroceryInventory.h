#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
	vector<GroceryItem> _inventory;
	float _taxRate;

public:
	GroceryInventory();      // constructor
	GroceryInventory(const float&);    // constructor
	GroceryInventory(const GroceryInventory& );  // Copy Constructor
	GroceryInventory& operator=(const GroceryInventory&);  //Assignment operator
	~GroceryInventory();  //Destructor

	GroceryItem& getEntry(const string&);
	void addEntry(const string&, const int&, const float&, const bool&);
	float getTaxRate() const;
	void setTaxRate(const float&);

	void createListFromFile(const string& filename);
	float calculateUnitRevenue() const;
	float calculateTaxRevenue() const;
	float calculateTotalRevenue() const;

	GroceryItem& operator[](const int&);
};

GroceryInventory::GroceryInventory()
{
	_taxRate = 0.0;

}

GroceryInventory::GroceryInventory(const float& invtaxrate)
{
	_taxRate = invtaxrate;
}


void GroceryInventory::addEntry(const string& grocName, const int& grocQuantity, const float& grocPrice, const bool& statement)
{
       GroceryItem temp(grocName, grocQuantity,grocPrice,statement);
       _inventory.push_back(temp);

}

GroceryItem& GroceryInventory::getEntry(const string& foo)
{
    for(size_t i = 0; i < _inventory.size();++i)
    {
        if(_inventory[i].getName() == foo )
        {
            return _inventory[i];

        }
    }
    GroceryItem emptyitem; //create an empty Grocery item obj, if does not find in _inventory
    return emptyitem;
}

float GroceryInventory::getTaxRate() const
{
	return _taxRate;
}

void GroceryInventory::setTaxRate(const float& invtaxrate)
{
	_taxRate = invtaxrate;
}

GroceryInventory::GroceryInventory(const GroceryInventory& a)  //Copy Constructor
{
    _inventory = a._inventory;
}

GroceryInventory& GroceryInventory::operator=(const GroceryInventory& _inventory)  //assignment operator
{
	return *this ;
}


GroceryInventory::~GroceryInventory()    //Destructor
{

}
//void GroceryInventory::createListFromFile(const string& filename) {
//	ifstream input_file(filename);
//
//	if (input_file.is_open()) {
//		cout << "Successfully opened file " << filename << endl;
//		string name;
//		int quantity;
//		float unit_price;
//		bool taxable;
//		while (input_file >> name >> quantity >> unit_price >> taxable) {
//			addEntry(name, quantity, unit_price, taxable);
//		}
//		input_file.close();
//	}
//	else {
//		throw invalid_argument("Could not open file " + filename);
//	}
//}
