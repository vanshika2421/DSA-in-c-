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

node* reverseLinkedList(node* &head){
    if(head -> next = NULL ){
        return head;
    }
    node* prev = NULL;
    node* curr = head;

    node* forward = curr -> next;
    while(curr != NULL){
        forward = curr-> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
};

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
    // print(head);
    insertAtHead(head, 13);
    // print(head);
    insertAtHead(head, 14);
    // print(head);
    insertAtHead(head, 15);
    // print(head);
    insertAtHead(head, 16);
    print(head);
    reverseLinkedList(head);
    print(head);


}