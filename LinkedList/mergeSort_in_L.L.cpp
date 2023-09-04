// Approach 1: split the L.L into two halves and sort using recursion and merge them 
// O(nlogn) : T.C
// O(logn) : S.C

Node* merge(Node* left , Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    // merge 2 sorted linked list
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
    }

    while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
    }

    ans=ans->next;
    return ans;
}


Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast ->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head){
    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // breaks linked list into 2 halves , after finding mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves

    Node* result = merge(left,right);

    return result;

}