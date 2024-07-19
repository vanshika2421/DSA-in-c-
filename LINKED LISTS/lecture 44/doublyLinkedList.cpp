#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int d) {
        this-> data = d;
        this-> prev = NULL;
        this-> next = NULL;
    }
    ~node(){
        int value = this-> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "value deleted: " << value << endl;

    }
};

void print(node* head){
    node* temp = head;
    while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
    }
    cout << endl;
}

int getLenght(node* &head){
    
    int lenght = 0;
    node* temp = head;

    while(temp != NULL){
    // cout << temp -> data << endl
    lenght++;
    temp = temp -> next;
    }
    // cout << lenght << endl;
    return lenght;
}

void insertAtHead( node* &head, int data){
    node* temp = new node(data);
    // = NULL;
    temp -> next = head;
    head-> prev= temp;
    head = temp;
    
}

void insertAtTail( node* &tail, int data){
    node* temp = new node(data);
    // = NULL;
    tail -> next = temp;
    temp-> prev= tail;
    tail = temp;
}

void insertAtPosition(node* & tail, node* head, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
    }
    else{
        node* temp  = head;
        int cnt = 1;
        while(cnt < position -1 ){
            temp = temp -> next;
            cnt++;
        }
        if (temp -> next == NULL)
        {
            insertAtTail(tail, data);
        }
        node* nodeToInsert = new node(data);
        nodeToInsert -> next = temp-> next;
        temp -> next -> prev = nodeToInsert;
        temp-> next = nodeToInsert;
        nodeToInsert -> prev = temp;
           
    }
}

void deleteNode(node* &head,  int position){   
    if(position == 1){
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }else{
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> prev = NULL;
        curr-> next = NULL;
        delete curr;
    }
}

int main(){
    node* node1 = new node(1);
    node* head = node1;
    node* tail = node1;
    // print(head);
    // getLenght(head);
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 4);
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtTail(tail, 6);
    print(head);
    insertAtPosition(tail, head, 2 , 100);
    print(head);
    // getLenght(head);
    // deleteNode(head, 2 );
    // print(head);
    // cout << "head: " << head -> data << endl;
    // cout << "tail: " << tail -> data << endl;
    deleteNode(head, 1);
    print(head);
    deleteNode(head, 6);
    print(head);
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;
}