#ifndef CART_H
#define CART_H
#include "Item.h"
#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<unordered_map>
using namespace std;

class Cart{
    private:
        unordered_map<int,Item> items;
        double total;
    public:
        Cart();
        bool isEmpty();
        void viewCart();
        void pickFromInventory(unordered_map<int,Product> mp);
        void checkout();
};

#endif