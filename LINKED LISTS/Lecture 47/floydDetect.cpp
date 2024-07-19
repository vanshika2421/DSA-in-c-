
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
