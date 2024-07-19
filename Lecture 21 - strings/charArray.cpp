#include<iostream>
using namespace std;

int main(){
    char name[20];
    cin >> name;
    name[2] = '\0'; // jahan null character aya wahaan hum ruk gye
    cout << " my name is : ";

    cout << name;
}