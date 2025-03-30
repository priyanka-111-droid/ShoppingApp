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

}


#endif