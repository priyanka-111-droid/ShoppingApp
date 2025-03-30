#ifndef CATEGORY_H
#define CATEGORY_H

#include<iostream>
#include<string>
#include<vector>
#include "Product.h"
using namespace std;

class Category{
    private:
        int categoryId;
        string categoryName;
        vector<Product> productLst;
        vector<Category> subcategories;
    public:
        //constructor
        Category(int categoryId)
        :categoryId(categoryId){}

        Category(string categoryName)
        :categoryName(categoryName){}

        Category(int categoryId,string categoryName,vector<Product> productLst={},vector<Category> subcategories={})
        :categoryId(categoryId), categoryName(categoryName), productLst(productLst),subcategories(subcategories){}

        //getter
        int getCategoryid() {
            return categoryId;
        }
        string getCategoryName(){
            return categoryName;
        }
        vector<Product> getProductLst(){
            return productLst;
        }
        vector<Category> getSubcategories(){
            return subcategories;
        }

        //add product
        void addProduct(const Product& product){
            productLst.push_back(product);
        }

        //operator overloading 
        bool operator < (const Category &c){
            //const tells us we are just comparing, not accidentally modifying
            if(categoryId<c.categoryId){
                return true;
            }
            return false;
        }

        bool operator > (const Category &c){
            //const tells us we are just comparing, not accidentally modifying
            if(categoryId<c.categoryId){
                return true;
            }
            return false;
        }

        bool operator==(const Category& c) const{
            return (categoryId==c.categoryId) || (categoryName==c.categoryName);
        }

        //display
        void displayProducts(){
            cout<<"Category Id: "<<categoryId<<",Category: "<<categoryName<<endl;
            for(auto& product:productLst){
                cout<<"Product id: "<<product.getId()<<","
                <<"Name: "<<product.getName()<<","
                <<"Price: "<<product.getPrice()<<","
                <<"Weight: "<<product.getWeight()<<endl;
            }
        }
};


#endif