#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void  queues(queue<int> &q){

    vector<int> ans;
    for(int i = 0; i < q.size(); i++){
        ans.push_back(q.front());
        q.pop();
    }

    // reverse(ans.begin(), ans.end());

    for(int i = 0; i <= ans.size() ; i++) {
        q.push(ans[i]);
    }
}

int main(){
    queue<int> q;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        q.push(value);
    }
    queues(q);
    for(int i = 0; i < q.size(); i++){
        cout << q.front() << " ";
        q.pop();
    }    
}