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


bool cheakLL(node* head){
    if(head == NULL){
        return true;
    }

    node* temp = head -> next;
    if(temp != NULL && temp != head){
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    return false;
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
    // node* head = new node(10);
    node* head = NULL;
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 13);
    // print(head);
    // insertAtHead(head, 14);
    // // print(head);
    // insertAtHead(head, 15);
    // // int x = print(head);
    // insertAtHead(head, 16);
    cout << "linked list is : " ;
    print(head);

    if(cheakLL(head)){ // pass the head else it will gonna give compile time error
        cout << "this is circular LL" << endl;
    }
    else{
        cout << "this is not circular LL" << endl;
    }
    
    }