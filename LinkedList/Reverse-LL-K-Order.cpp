// // Coding Ninja Question

// Approach =-> Reaverse the first k node and call the recursion now recursion can handle rest of the thing

// T.C = O(n)
// S.C = O(n)



Node* kReverse(Node* head, int k){
    // base case 
    if(head == NULL){
        return NULL;
    }

    // step1: reverse first K nodes 
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count = 0;

    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka

    if(next != NULL){
        head->next = kReverse(next,k);
    }

    // step3: return head of reversed List
    return prev;
}