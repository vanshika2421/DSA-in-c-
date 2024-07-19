
node* getStartingNode(node* &head){
    if(head == NULL){
        return NULL;
    }
    node* intersection = floydDetection(head);
    node* slow  = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}