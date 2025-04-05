#include "Product.h"
#include "Inventory.h"
#include "Graph.h"
#include <unordered_map>
#include<utility>

/**
 * constructor
 */
Inventory::Inventory(vector<Product> inventory)
:inventoryStock(),productNamePriceLst(),productWeightLst(){
    for(Product p:inventory){
        inventoryStock[p.getId()] = p;
        productNamePriceLst.push_back({p.getName(),p.getPrice()});
        productWeightLst.push_back(p.getWeight());
    }
}

/**
 * method to correctly print product details
 */
void Inventory::displayInventory(){
    for(auto &x:inventoryStock){
        cout<<x.first<<" - "<<x.second.getName() << " - "<<x.second.getPrice() << " - "<<x.second.getWeight()<<endl;
    }
}

/**
 * method to return inventory stock
 */
unordered_map<int,Product> Inventory::getInventoryStock(){
    return inventoryStock;
}

/**
 * recommend items under certain weight
 */
double Inventory::recommendGroceriesUnderWeight(double weight){
    //knapsack
    //bottom-up dp
    int N = inventoryStock.size();
    vector<vector<int>> dp(N+1,vector<int>(weight+1,0));
    for(int n=1;n<=N;n++){
        for(int w=1;w<=weight;w++){
            int inc = 0,exc = 0;
            if(productWeightLst[n-1]<=w){
                inc = productNamePriceLst[n-1].second + dp[n-1][w-productWeightLst[n-1]];
            }
            exc = dp[n-1][w];

            dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][weight];
}

void Inventory::homeDelivery(string src,string dest){
    //dijkstra for shortest path
    vector<string> cities = {"Singapore","Berlin","New York","New Delhi","Paris"};
    Graph g(cities);
    g.addEdge("Singapore","Berlin",4,true);
    g.addEdge("Singapore","New York",2,true);
    g.addEdge("Berlin","New York",5,true);
    g.addEdge("Berlin","New Delhi",10,true);
    g.addEdge("New York","New Delhi",3,true);
    g.addEdge("New York","Paris",8,true);
    g.addEdge("New Delhi","Paris",7,true);

    cout<<"Shortest path:"<<g.dijkstra(src,dest)<<endl;
}