#ifndef GRAPH_H
#define GRAPH_H

#include "City.h"
#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<unordered_map>
#include<string>
#include<set>
#include<climits>
using namespace std;

class Graph{
    private:
        unordered_map<string,City*> mp;//name of city, pointer to city node
    public:
        Graph(vector<string> cities){
            for(auto city:cities){
                mp[city] = new City(city);
            }
        }

        void addEdge(string src,string dest,int weight,bool unDir=false){
            mp[src]->neighbours.push_back({dest,weight});
            if(unDir){
                mp[dest]->neighbours.push_back({src,weight});
            }
        }
        /**
         * dijkstra algo - shortest path from single point algo
         */
        int dijkstra(string src,string dest){
            //init
            unordered_map<string,int> dist;
            for(auto &cityName:mp){
                dist[cityName.first] = INT_MAX;//initialize dist to inf
            }

            set<pair<int,string>> s; //set of pair<dist,citynode>

            dist[src] = 0;
            s.insert({0,src});

            while(!s.empty()){
                auto current = *s.begin();
                s.erase(s.begin());

                string cityNode = current.second;
                int cityDist = current.first;

                if(cityNode==dest){
                    //reached dest 
                    return cityDist;
                }

                //visit all neighbours of cityNode
                for(auto neighbour:mp[cityNode]->neighbours){
                    string neighbourNode = neighbour.first;
                    int neighbourWeight = neighbour.second;

                    if(cityDist+neighbourWeight<dist[neighbourNode]){
                        //if old node exists,remove it
                        if(dist[neighbourNode]!=INT_MAX){
                            s.erase(s.find({dist[neighbourNode],neighbourNode}));
                        }

                        //update 
                        dist[neighbourNode] = cityDist + neighbourWeight;
                        s.insert({dist[neighbourNode],neighbourNode});
                    }
                }
            }
            return -1;
        }
};


#endif