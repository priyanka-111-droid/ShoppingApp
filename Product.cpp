#include "Product.h"

Product::Product() : id(),name(),price() {}

Product::Product(int id,string name,double price,double weight)
:id(id),name(name),price(price),weight(weight){}

int Product::getId(){
    return id;
}

string Product::getName(){
    return name;
}

double Product::getPrice(){
    return price;
}

double Product::getWeight(){
    return weight;
}

void Product::displayProductInfo(){
    cout<<"\t"<<"Id:"<<id<<endl;
    cout<<"\t"<<"Name:"<<name<<endl;
    cout<<"\t"<<"Price:$"<<price<<endl;
    if(weight!=0.0){
        cout<<"\t"<<"Weight:"<<weight<<"kg"<<endl;
    }
}