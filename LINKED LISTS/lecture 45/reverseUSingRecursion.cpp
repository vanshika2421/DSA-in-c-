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

void reverse(node* &head, node* prev, node* curr){
    if(curr == NULL){
        head = prev;
        return ;
    }
    reverse(head,curr,curr->next);
    curr-> next = prev;
}

void insertAtHead(node* &head, int data){
    node* temp = new node(data);
    temp -> next = head;
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

node* reverseLL(node* head){
    node* curr = head;
    node* prev = NULL;
    reverse(head, prev, curr);
    return head;
}

int main(){
    node* head = new node(10);
    insertAtHead(head, 34);
    // print(head);
    insertAtHead(head, 4);
    // print(head);
    insertAtHead(head, 78);
    // print(head);
    insertAtHead(head, 23);
    
    
    cout << "Original linked list: ";
    print(head);

    head = reverseLL(head);

    cout << "Reversed linked list: ";
    print(head);



    while (head != NULL)
    {
        node* temp = head;
        head = head-> next;
        delete temp;
    }
    
}