#include "Product.h"
#include "Category.h"
#include "helper.h"
#include "CategoryBST.h"

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<utility>//for pair
using namespace std;

vector<Category> categoryInventory = createCategoryInventory();

void user(){

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
        cout<<"Enter 1 for admin,2 for user,3 to quit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                user();
            case 2:
                admin();
            case 3:
                cout<<"Exit"<<endl;
                return -1;
            default:
                cout<<"Incorrect option selected"<<endl;
        }
    }
    return 0;
}

