#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    //constructor
    node(int d){
        this-> data = d;
        this-> next = NULL;
    }
    ~node(){
        int value = this-> data;
        if(this-> next != NULL){
            delete next;
            next = NULL;
        }
        cout << " deleted value is: " << value << endl; 
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



void insertNode(node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        node* newNode  = new node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        node* temp = new node(d);
        node* curr = tail;
        // curr -> next = temp;
        // node* forward = curr -> next;
        // temp -> next = forward;
        while(curr -> data != element){
            curr - curr-> next;
        } 
        // node* temp = new node(d);
        temp-> next = curr-> next;
        curr-> next = temp;
    }
} 
void print(node* tail){
    node* temp = tail;
    cout << tail -> data  << " ";
    while(tail-> next != temp){
        cout<< tail-> data << " ";
        tail = tail -> next;
    }
    cout << endl;

    // OR
    // node* temp = tail;
    // do{
    //     cout << tail-> data << endl;
    //     tail = tail-> next;
    // }while(tail != temp);
}

void deleteNode(node* &tail, int value)
{
if (tail == NULL){
    cout << " List is empty, please check again" << endl;
}
else{
    node* prev = tail;
    node* curr = prev -> next;
    while(curr -> data != value) {
        prev = curr;
        curr = curr -> next;
    }
     prev -> next = curr -> next;
     curr -> next = NULL;
     delete curr ;
}

}// empty list

int main()
{
    node* tail = NULL;
    // insertNode(tail,3, 3);
    // print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5, 7);
    print(tail);
    // insertNode(tail, 5, 6);
    // print(tail);
    insertNode(tail, 7,8);
    print(tail);
    insertNode(tail,7,11);
    print(tail);
    // deleteNode(tail, 6);
    // print(tail);

    if(cheakLL){
        cout << "this is circular LL" << endl;
    }
    else{
        cout << "this is not circular LL" << endl;
    }
    
} 
 