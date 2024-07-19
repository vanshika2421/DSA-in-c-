#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        this-> data = d;
        this-> next = NULL;
    }
};


node* kReverse(node* head, int k){
    //base case
    if(head = NULL){
        return NULL;
    }
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;
    
    //reversing k nodes
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // 2-> recursion dekhlega
    if(next != NULL){
        head-> next = kReverse(next, k);
    }

    // reverse head of of reverse list
    return prev;
}


void insertAtHead(node* &head, int data){
    node* temp = new node(data);
    temp-> next = head;
    head = temp;
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main(){
    node* node1 = new node(10);
    node* head;
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);
    insertAtHead(head, 14);
    print(head);
    insertAtHead(head, 15);
    print(head);
    insertAtHead(head, 16);
    print(head);
    // reverse(head,2);
    // print(head);
    head = kReverse(head, 2);
    print(head);


}