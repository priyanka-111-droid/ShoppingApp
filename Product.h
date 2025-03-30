#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
using namespace std;

class Product{
    private:
        int id;
        string name;
        double price;
        double weight;//not needed for every item, only Groceries
    public:
        Product();
        Product(int id,string name,double price,double weight=0.0);
        int getId();
        string getName();
        double getPrice();
        double getWeight();
        void displayProductInfo();
};



#endif
