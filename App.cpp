#include "Product.h"
#include "Category.h"
#include "helper.h"
#include "CategoryBST.h"
#include "Inventory.h"
#include "Cart.h"

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<utility>//for pair
using namespace std;

vector<Category> categoryInventory = createCategoryInventory();//for admin
vector<Product> mockInventory = createInventory();//user

void user(){
    cout<<"Welcome to Shopping App!"<<endl;
    Inventory i(mockInventory);
    Cart c;

    while(true){
        char ch;
        cout<<"Press 'a' to add item, 'v' to view cart,'r' for grocery recommendation,'c' for checkout and 'e' to exit"<<endl;
        cin>>ch;

        switch(ch){
            case 'a':
                i.displayInventory();
                c.pickFromInventory(i.getInventoryStock());
                break;
            case 'v':
                c.viewCart();
                break;
            case 'c':
            {
                c.checkout();
                string start;
                cout<<"Enter destination for order pickup(Singapore,Berlin,New York,New Delhi,Paris)";
                cin>>start;
                string drop;
                cout<<"Enter destination for order drop(Singapore,Berlin,New York,New Delhi,Paris)";
                cin>>drop;
                i.homeDelivery(start,drop);
                break;
            }
            case 'r':
                i.displayInventory();
                double wt;
                cout<<"Enter max weight of groceries you would like"<<endl;
                cin>>wt;
                cout<<i.recommendGroceriesUnderWeight(wt)<<endl;
                break;
            case 'e':
                cout<<"Thank you for shopping!"<<endl;
                return;
            default:
                cout<<"Press 'a','v','c','r','e' only"<<endl;
        }
    }
}


void admin(){

    CategoryBST<Category> tree;
    for(auto& category: categoryInventory){
        tree.insert(category);
    }

    tree.displayPreorder();
    cout<<"====="<<endl;

    cout<<(tree.search(Category(500)) ? "Found" : "Not Found")<<endl;
    cout<<(tree.search(Category("Items")) ? "Found":"Not Found")<<endl;

    cout<<"There are "<<tree.count()<<" categories"<<endl;
    cout<<"There are "<<tree.countLeaves()<<" leaves."<<endl;
    cout<<"Height is "<<tree.height()<<endl;

    tree.deleteNode(Category(2100));
    tree.displayPreorder();

}


int main(){
    while(true){
        int choice;
        cout<<"Enter 1 for user and 2 for admin and 3 to quit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                user();
                break;
            case 2:
                admin();
                break;
            case 3:
                cout<<"Exit"<<endl;
                return -1;
            default:
                cout<<"Incorrect option selected"<<endl;
        }
    }
    return 0;
}

