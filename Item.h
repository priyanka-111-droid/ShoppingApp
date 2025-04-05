#ifndef ITEM_H
#define ITEM_H

#include "Product.h"
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class Item{
    Product p;
    double price;
    public:
        int quantity;
        Item();
        Item(Product p,int quantity);
        double getItemQuantity();
        double getItemPrice();
        void displayItemInfo();
};


#endif