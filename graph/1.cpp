#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class maps{
    public:
    unordered_map<int, list<int>> umap;

    void addedge(int u, int v, int direction){
        umap[u].push_back(v);
        if(direction == 0){
            umap[v].push_back(u);
        }
    }

    void print(){
        for(auto i: umap){
            cout << i.first << " ";
            for(auto j : i.second){
                 cout << j << ", ";
            }
            cout << endl;
        }
    }

}; 

int main(){
    int n; // number of nodes
    int m; // number of edges
    cin >> n;
    cin >> m;

    maps g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u; 
        cin >> v;
        g.addedge(u,v,1);
        g.print();
    }

}