// Coding Ninja Question

// Approach 1 using a traversal a linked List and find its length
// Time Complexity = O(n);
// Space Complexity = O(1);

int getLength(Node* &head){
    int len = 0;

    while(head != NULL){
        len++;
        head = head->next;
    }

    return len;
}


Node* findMiddle(Node* head){
    int len = getLength(head);

    int ans = len/2;

    int cnt = 0;
    Node* temp =head;
    while(cnt<ans){
      temp = temp->next;
      cnt++;
    }

    return temp;
}


// Approch 2 using a two player , first player goes 2 times faster than second player when first player at the end of L.l then second player is at middle (return second -> ans);

Node* getMiddle(Node* &head){
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL) fast = fast-next;

        slow = slow->next;
    }

    return slow;
}

Node* findMiddle(Node* head){
    return getMiddle(head);
}