#include<iostream>
using namespace std;

int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n){
    int* ptr = &n;
    return ptr;
}

int main(){
int n = 5;
func(n);
fun(n);
} 
