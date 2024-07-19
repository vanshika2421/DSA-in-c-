#include<iostream>
using namespace std;

void update(int **p){
    p = p+1;

    *p = *p +1;
     
    **p =**p + 1; 
}


int main(){
    int i = 5;
    cout << "value is :" << i << endl;
    int *ptr1 = &i;
    cout << "value of single pointer, storing address of i : " << ptr1 << endl;
    int **ptr2 = &ptr1;
    cout << "value of double pointer, storing address of ptr1 :" << ptr2 << endl;
    int ***ptr3 = &ptr2;
    cout << "value of double pointer, storing address of ptr2 :" << ptr3 << endl;
    cout << "------------------------" << endl;
    cout << "value : " << i << endl;
    cout << "single pointer: "  << *ptr1 << endl; 
    cout << "double pointer: " << **ptr2 << endl;
    cout<< "triple pointer: "  <<  ***ptr3 << endl;
    cout << "------------------------" << endl;
    cout << "address : " << &i << endl;
    cout << "single pointer: "  << &ptr1 << endl; 
    cout << "double pointer: " << &ptr2 << endl;
    cout<< "triple pointer: "  <<  &ptr3 << endl;

    // update(ptr3);


}
