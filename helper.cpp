#include "Product.h"
#include "Category.h"
#include<vector>
using namespace std;

vector<Product> createInventory(){
    return{
        Product(1900,"Apples",20,5),
        Product(2100,"Oranges",90,10),
        Product(200,"iPhone16",99),
        Product(600,"Samsung",76)
    };
}

vector<Category> createCategoryInventory(){
    vector<Product> products = {
        Product(1900,"Apples",20,5),
        Product(2100,"Oranges",90,10),
        Product(200,"iPhone16",99),
        Product(600,"Samsung",76)
    };

    Category cat2(500,"Electronics",{products[2],products[3]});
    Category cat6(2000,"Groceries",{products[0],products[1]});

    Category cat3(
        1500,
        "Items",
        {},
        {cat2,cat6}
    );
    
    return {cat3,cat2,cat6};
}

