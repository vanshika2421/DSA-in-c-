#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this-> next = NULL;
        }
        cout << value << " <- this node is deleted" << endl;
    }    
    };

void insertAtHead(node* &head, int data){
    node* temp= new node(data);
    // |   | <- temp   |   | -> head
    temp -> next = head;
    head = temp;
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

void insertAtTail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(node* tail, node* &head, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
    }

    node* temp = head;
    int cnt;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
    }
    node* nodeToInsert = new node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(node* &head, node* &tail, int position){
    // del start node
    if(position == 1){
        node* temp = head;
        head = head-> next;
        temp -> next = NULL;
        delete temp;
    }
    //del n or last node
    else{
        node* prev = NULL;
        node* curr = head;

        int count = 1;
        while(count <= position){
            prev = curr;
            curr = curr-> next;
            count++;
        }
        prev -> next = curr-> next;
        curr-> next = NULL;
        delete curr;

    }
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtHead(head, 34);
    print(head);
    // cout << endl;
    insertAtTail(tail, 56);
    print(head);
    insertAtPosition(tail, head, 2, 33);
    print(head);
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;
    deleteNode(head, tail,3);
    print(head);
    deleteNode(head, tail,2 );
    print(head);
    // cout << "head : " << head -> data << endl;
    // cout << "tail : " << tail -> data << endl;
}