#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    stack<int> s;

    int n;
    cin >>n;
    cout << "------------" << endl;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        q.push(value);
    }
    cout << "------------" << endl;

    int k;
    cout << " window size" << " ";
    cin >> k;



    for(int i = 0; i <k; i++){
        int value = q.front();
        q.pop();
        s.push(value);
    }

    while(!s.empty()){
        int value = s.top();
        s.pop();
        q.push(value);
    }

    int t = q.size() - k;
    
    while(t--){
        int value = q.front();
        q.pop();
        q.push(value);
    }
    int size = q.size(); // always define queues size after the loops then use it.
    for(int i = 0; i < size; i++){
        cout << q.front() << " ";
        q.pop();
    }
}