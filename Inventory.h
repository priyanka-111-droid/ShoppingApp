#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<utility>

using namespace std;

class Inventory{
    private:
        unordered_map<int,Product> inventoryStock;
        vector<pair<string,double>> productNamePriceLst;
        vector<double> productWeightLst;
    public:
        Inventory(vector<Product> inventory);
        void displayInventory();
        unordered_map<int,Product> getInventoryStock();
        double recommendGroceriesUnderWeight(double weight);
        void homeDelivery(string src,string dest);
};

#endif