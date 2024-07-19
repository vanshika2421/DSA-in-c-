#include<iostream>
using namespace std;

int main(){
    char c = 'q';
    char *ch = &c;
    cout << ch << endl; //ch address return nahi krta..content return krta hai
    cout << &ch << endl;
    cout << sizeof(ch) << endl;
    cout << sizeof(c) << endl;
}