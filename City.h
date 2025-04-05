#ifndef CITY_H
#define CITY_H 

#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<unordered_map>
#include<string>
#include<cstring>
using namespace std;

class City{
    public:
        string name;
        vector<pair<string,int>> neighbours; //neighbour,weight

        City(string name){
            this->name = name;
        }
};

#endif