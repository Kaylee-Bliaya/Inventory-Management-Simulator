// Kaylee Bliaya    04/08/2020
// Section 17
// Assignment 02
// This program simulates an inventory management system for a shop.

#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_ITEMS = 4;
void print(Item inventory[NUM_ITEMS]); // function prints out the inventory
void purchase(Item inventory[NUM_ITEMS]); // function calculates the purchases
void sale(Item inventory[NUM_ITEMS]); // function calculates the purchases when the items are on sale

int main()
{
    Item inventory[NUM_ITEMS]; // create an array of 4 using class Item
    char option;
    int itemsSold = 0; // counter that counts how many items have been sold

    cout << "===Welcome to the inventory helper===\n";
    cout << "-store hours will being shortly-\n";
    cout << "Please update your inventory...\n\n";

    // for loop initializes the name, id number, retail value,
    // and quantity of the items in inventory
    for (int num = 0; num < NUM_ITEMS; num++)
    {
        string n;
        int i;
        double v;
        int q;

        cout << "Enter item " << num + 1 << " to add to inventory.\n";
        cout << "Please enter the product name.\n";
        getline(cin, n);
        inventory[num].setName(n);

        cout << "Enter the product manufacturer's id.\n";
        cin >> i;
        inventory[num].setId(i);

        cout << "Enter the retail value.\n";
        cin >> v;
        inventory[num].setValue(v);

        cout << "Enter the quantity available.\n";
        cin >> q;
        inventory[num].setQuant(q);

        cin.ignore();
    }

    print(inventory); // function prints out the inventory in stock
    
    cout << "Business hours are now open\n";

    do
    {
        cout << "Would you like to perform a transaction? (y/n)\n";
        cin >> option;

        // if the user input 'y' and they have purchased less than 2
        // items then the function purchase is called
        if (itemsSold < 2 && option != 'n')
        {
            purchase(inventory);
        }
        // if the user input 'y' and they have purchased 2 or more
        // items then the function sale is called
        if (itemsSold >= 2 && option != 'n')
        {
            sale(inventory);
        }
        
        itemsSold++; // counter keeps track of how many items sold
    } while (option != 'n');

    // if the user inputs 'n', then the closing statement and 
    // inventory is printed out
    cout << "Closing Shop -- inventory left\n";
    print(inventory);

    system("PAUSE");
    return 0;
}

// function prints out the inventory
// input = array of class Item
void print(Item inventory[NUM_ITEMS])
{
    cout << '\n';
    for (int num = 0; num < NUM_ITEMS; num++)
    {
        cout << fixed << setprecision(2) << num + 1 << ". " << inventory[num].getQuant() << ' ' 
            << inventory[num].getName() << " left in stock at $" << inventory[num].getValue() 
            << " item id " << inventory[num].getId() << '\n';
    }
}

// function calculates the purchases of the user
// input = array of class Item
void purchase(Item inventory[NUM_ITEMS])
{
    int item, amnt;
    double price;

    cout << "====Menu====\n" << "Enter which item you would like to purchase";
    
    print(inventory); // print out the inventory list

    cin >> item;
    cout << "How many would you like to buy?\n";
    cin >> amnt;
    // if the amount the user enters is greater than the amount in stock, ask the user to 
    // input another amount
    if (amnt > inventory[item - 1].getQuant())
    {
        cout << "Not enough " << inventory[item - 1].getName() << " in stock (" 
            << inventory[item - 1].getQuant() << ") total stock\n" << "Enter new amount\n";
        cin >> amnt;
    }

    price = inventory[item - 1].getValue() * amnt; // calculates the cost of the purchase
    // prints out what the user purchased and the cost
    cout << fixed << setprecision(2) << "SOLD " << amnt << ' ' << inventory[item - 1].getName() 
        << " for $" << price << "\n\n";
    amnt = inventory[item - 1].getQuant() - amnt; // decrease the amount of the item sold in stock
    inventory[item - 1].setQuant(amnt); // set the item quantity to the previously calculated amount
}

// function calculates the purchases of the user when the items are on sale
// input = array of class Item
void sale(Item inventory[NUM_ITEMS])
{
    double discount, salePrice;
    char choice;

    cout << "\n2 items sold!\n" << "Sale starting!\n" << "Would you like to enter a discount %? (y/n)\n";
    cin >> choice;
    if (choice == 'y') 
    {
        cout << "Enter the custom discount percentage.\n";
        cin >> discount;
        
        for (int num = 0; num < NUM_ITEMS; num++)
        {
            // the retail values of the items when the discount is applied are calculated
            salePrice = inventory[num].getValue() * (1 - discount); 
            inventory[num].setValue(salePrice); // set the item retail value to the previously calculated sale price
            // print out the new prices of the items in stock
            cout << fixed << setprecision(2) << "Price for " << inventory[num].getName() << " on sale for $"
                << inventory[num].getValue() << '\n';
        }
        purchase(inventory); // call the purchase function 
    }
}

/*
---Sample Output---
===Welcome to the inventory helper===
-store hours will being shortly-
Please update your inventory...

Enter item 1 to add to inventory.
Please enter the product name.
pencils
Enter the product manufacturer's id.
8541
Enter the retail value.
0.89
Enter the quantity available.
10
Enter item 2 to add to inventory.
Please enter the product name.
water
Enter the product manufacturer's id.
6213
Enter the retail value.
2.50
Enter the quantity available.
50
Enter item 3 to add to inventory.
Please enter the product name.
cookies
Enter the product manufacturer's id.
4123
Enter the retail value.
2.99
Enter the quantity available.
15
Enter item 4 to add to inventory.
Please enter the product name.
backpack
Enter the product manufacturer's id.
7891
Enter the retail value.
30.50
Enter the quantity available.
5

1. 10 pencils left in stock at $0.89 item id 8541
2. 50 water left in stock at $2.50 item id 6213
3. 15 cookies left in stock at $2.99 item id 4123
4. 5 backpack left in stock at $30.50 item id 7891
Business hours are now open
Would you like to perform a transaction? (y/n)
y
====Menu====
Enter which item you would like to purchase
1. 10 pencils left in stock at $0.89 item id 8541
2. 50 water left in stock at $2.50 item id 6213
3. 15 cookies left in stock at $2.99 item id 4123
4. 5 backpack left in stock at $30.50 item id 7891
4
How many would you like to buy?
6
Not enough backpack in stock (5) total stock
Enter new amount
2
SOLD 2 backpack for $61.00

Would you like to perform a transaction? (y/n)
y
====Menu====
Enter which item you would like to purchase
1. 10 pencils left in stock at $0.89 item id 8541
2. 50 water left in stock at $2.50 item id 6213
3. 15 cookies left in stock at $2.99 item id 4123
4. 3 backpack left in stock at $30.50 item id 7891
1
How many would you like to buy?
3
SOLD 3 pencils for $2.67

Would you like to perform a transaction? (y/n)
y

2 items sold!
Sale starting!
Would you like to enter a discount %? (y/n)
y
Enter the custom discount percentage.
0.50
Price for pencils on sale for $0.45
Price for water on sale for $1.25
Price for cookies on sale for $1.50
Price for backpack on sale for $15.25
====Menu====
Enter which item you would like to purchase
1. 7 pencils left in stock at $0.45 item id 8541
2. 50 water left in stock at $1.25 item id 6213
3. 15 cookies left in stock at $1.50 item id 4123
4. 3 backpack left in stock at $15.25 item id 7891
3
How many would you like to buy?
6
SOLD 6 cookies for $8.97

Would you like to perform a transaction? (y/n)
n
Closing Shop -- inventory left

1. 7 pencils left in stock at $0.45 item id 8541
2. 50 water left in stock at $1.25 item id 6213
3. 9 cookies left in stock at $1.50 item id 4123
4. 3 backpack left in stock at $15.25 item id 7891
*/
