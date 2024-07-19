#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int op;
    cin >> op;

    switch (op){
        case '+':cout << a+b << endl;
        break;
         case '-':cout << a-b << endl;
        break;
         case '*':cout << a*b << endl;
        break;
         case '/':cout << a/b << endl;
        break;

    }

}