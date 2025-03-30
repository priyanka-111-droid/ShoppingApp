#include "Product.h"
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<utility>//for pair
using namespace std;

void user(){

}


void admin(){
    
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

