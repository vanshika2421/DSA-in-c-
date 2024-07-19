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

node* getMiddle(node* head){
    if(head-> next = NULL){
        return head;
    }
    if(head-> next -> next = NULL){
        return head-> next;
    }
    node* slow;
    node* fast = head-> next;

    while(fast !=NULL){
        fast = fast -> next;
    if(fast !=NULL){
        fast = fast -> next;
    }
    slow = slow -> next;
    }
         return slow;
}

// void length(node* &head){
//     int len =  0;
//     node* temp = head;
//     while(temp != NULL){
//         len++;
//     }
//     return len;
// }


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
    // print(head);
    getMiddle(head);
    print(head);


}