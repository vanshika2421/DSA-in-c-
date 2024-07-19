#include<iostream>
using namespace std;

void update2(int& x){
    x = x + 1;
}

void update1(int n){
    n = n + 1;
}


int main(){
    int i = 7;
    int& j = i;
    cout << i << endl;
    cout << i++ << endl;
    cout << j++ << endl;
    cout << j << endl;
    cout << i << endl;
    cout << "-------------------------------------" << endl;
    // WHY IT IS USED -> TO PASS THE SAME VARIABLE OIN FUCNTION DECLARATION
    int n = 7;
    // cin >> n;
    cout << "before :" << n << endl;
    update1(n);
    cout << "after: " << n << endl;
    // cout << i << endl;
    cout << "-------------------------------------" << endl;
       int x = 7;
    // cin >> n;
    cout << "before :" << x << endl;
    update2(x);
    cout << "after: " << x << endl;
    // cout << x << endl;

    



}