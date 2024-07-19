#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void prepared(unordered_map<int,list<int>> &listt, vector<pair<int,int>> &edges){
    for(int i = 0; i < edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        listt[u].push_back(v);
        listt[v].push_back(u);
    }
}

void queuesbfs(unordered_map<int,list<int>> &listt, 
unordered_map<int,bool> &visited, vector<int>& ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i: listt[frontNode]){
            if(visited.find(i) == visited.end()){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void bfs(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,list<int>> listt;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepared(listt, edges);


    for(int i = 0; i < vertex; i++){
        if(!visited[i])
            queuesbfs(listt,visited,ans,i);
    }

    for(int i = 0;i<ans.size()-1;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main(){
    int n;
    cout << "enter nodeS:";
    cin >> n;

    int m;
    cout << "enter edges" ;
    cin >> m;

    vector<pair<int,int>> edges;

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u ;
        cin >> u;
        edges.push_back(make_pair(u,v));
    }

    bfs(n,edges);
}
