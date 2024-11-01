#include<bits/stdc++.h> // include header files
using namespace std; 

class node{ // added class 
    public:
    int data;
    node* next;
    node(int d){
        this-> data = d;
        this-> next = NULL;
    }
};

node* floydDetection(node* &head){
    if(head == NULL){
        return NULL;
    }
    node* slow = head;
    node* fast = head;

    while(slow && fast){ // this means jab tk dno null na hojaye
    slow = slow-> next;
    fast = fast -> next -> next;
    if(slow ==fast){
        cout << "present at : " << slow -> data << endl;
        return slow;
    }
    }
    return NULL;
}
