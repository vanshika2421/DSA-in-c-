#include<iostream>
using namespace std;

// void print(int *p){
//     cout << "value of p is -> " << *p << endl;
//     cout << "address of p is -> " << p << endl;
//     *p = *p+1;
//     cout << "address of p is -> " << p << endl;
//     cout << "incremented value of p is -> " << *p << endl;
// }


// int main(){
//     int value = 5;
//     int *p = &value;
//     print(p);
    
// }

void changeSign(int *p){
  *p = (*p)  *  -1;
}

int main(){
  int a = 10;
  changeSign(&a);
  cout << a << endl;
}