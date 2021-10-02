#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
	private:
		string name; // item name
		int id; // item manufactuer's id
		double value; // item retail value
		int quant; // item quantity available
	public:
		// setters for name, id, value, and quantity
		void setName(string n);
		void setId(int i);
		void setValue(double v);
		void setQuant(int q);
	
		// getter for name, id, value, and quantity
		string getName();
		int getId();
		double getValue();
		int getQuant();
};

void Item::setName(string n)
{
	name = n;
}
void Item::setId(int i)
{
	id = i;
}
void Item::setValue(double v)
{
	value = v;
}
void Item::setQuant(int q)
{
	quant = q;
}

string Item::getName()
{
	return name;
}
int Item::getId()
{
	return id;
}
double Item::getValue()
{
	return value;
}
int Item::getQuant()
{
	return quant;
}
#endif