#include "Product.h"
#include "Item.h"
#include<unordered_map>

//default constructor
Item::Item()
:p(),quantity(0),price(0.0){}

//constructor with initialization list
Item::Item(Product p,int quantity)
:p(p),quantity(quantity),price(0){
    price = quantity*p.getPrice(); //can also write friend class Item here
}

//can also use assignment in constructor

double Item::getItemQuantity(){
    return quantity;
}

double Item::getItemPrice(){
    return price;
}

void Item::displayItemInfo(){
    cout<<"ITEM"<<endl;
    p.displayProductInfo();
    cout<<"\t"<<"Quantity:"<<quantity<<endl;
    cout<<"\t"<<"Item Price:"<<price<<endl;
    cout<<"===================="<<endl;
}