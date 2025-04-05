#include "Cart.h"
#include "Item.h"
#include "Product.h"
#include<utility>
#include<unordered_map>

Cart::Cart()
:items(),total(){}

bool Cart::isEmpty(){
    return items.empty();
}

/**
 * pickFromInventory() picks up items form inventory and adds to cart.
 */
void Cart::pickFromInventory(unordered_map<int,Product> mp){
    int idChoice = 0;
    cout<<"Enter id of item you want"<<endl;
    cin>>idChoice;

    int q = 0;
    cout<<"Enter quantity of item"<<endl;
    cin>>q;

    if(items.count(idChoice)==0){
        //create product and item
        Product p(mp[idChoice].getId(),mp[idChoice].getName(),mp[idChoice].getPrice(),mp[idChoice].getWeight());
        Item item(p,q);
        items[idChoice] = item;
    }else{
        items[idChoice].quantity += q;
    }
    cout<<"Items added successfully"<<endl;
}

void Cart::viewCart(){
    if(!isEmpty()){
        for(auto &x:items){
            cout<<x.first<<endl;
            x.second.displayItemInfo();
        }
    }else{
        cout<<"Cart is empty"<<endl;
    }
}

void Cart::checkout(){
    if(!isEmpty()){
        for(auto &x:items){
            total+=x.second.getItemPrice();
        }
        cout<<"Amount to pay: "<<total<<endl;
    }else{
        cout<<"Amount to pay: 0"<<endl;
    }
}