// Approch 1 --> if current node is different than move the current pointer otherwise delete the duplicates and point current->next = current-next-next

// O(n) = T.C
// O(1) = S.C


Node* uniqueSortedList(Node* head){
    // Empty List 
    if(head == NULL) {
        return NULL;
    }

    // non empty list

    Node* curr = head;

    while(curr->next != NULL)
    {
        if(curr -> data == curr -> next -> data){
            Node* next_next = curr ->next ->next; 
            Node* nodeToDelete = curr ->next;
            delete(nodeToDelete);
        }
        else // not equal 
        {
            curr = curr -> next;
        }
    }

    return head;
}

