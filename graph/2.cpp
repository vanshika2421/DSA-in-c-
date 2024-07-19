#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graphs{
    public:
    unordered_map<int, list<int>> gr;
    
    void addEdge(int u, int v, int direction){
        gr[u].push_back(v);
        if(direction == 0){
            gr[v].push_back(u); // graph ke u pr v ki direction push kredenge.
        }
    }
    void print(){
        // map -> <first -> int, second -> list>
        // 0 -> 1
        // 0 -> 2
        // 1 -> 0;
        for(auto i : gr){
            cout << i.first << " ";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl; 
        }
    }

};

int main(){
    int n;
     cout << "Enter the number of Nodes: " << " ";
    cin >>  n ;

    int m;
    cout << " enter the number of edges" << " ";
    cin >> m;

    graphs g;

    for(int i= 0; i < m; i++){
        int u, v;
        cin >> u;
        cin >> v;
        g.addEdge(u,v,0); // direction 1 doge to directed graph bnjayega.
        g.print();
    }
}