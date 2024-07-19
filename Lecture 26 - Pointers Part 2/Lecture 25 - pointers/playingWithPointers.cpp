#include<iostream>
using namespace std;

int main(){
    //never do this
    // bad practice
    // this is pointer created randomly which is pointing a garbage value
    // int *p;
    // cout << *p << endl;
    int i = 5;
    int *p = &i;
    // p = &i;
    cout << p << endl; // address
    cout << *p << endl; // value
    cout << i << endl; // value 

    int num = 10;
    int a = num;
    a++;
    cout << num << endl;
    int *po = &num;
    cout << num << endl;
    (*po)++;
    cout << num << endl;

    int j = 10;
    int *t = &j;
    *t = *t +1;
    cout << (*t) <<endl; 
    cout << t << endl;
    t = t + 1;
    cout << t << endl;
     

}