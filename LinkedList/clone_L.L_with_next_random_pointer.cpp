// Approach 1 ==> map the original L.L with the Clone L.L and set the random pointer with the help of original L.L

// O(n)-> T.C
// O(n)-> S.C


void insertAtTail(Node* &head, Node* &tail ,int d){

    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }


}

Node* copyList(Node* head){
    // step 1: Create a clone list 
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != head){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Step2: Create a map 
    unordered_map<Node* , Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode!=NULL && cloneNode != NULL){
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step3 : Arrange random pointer

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL){
        cloneNode->random = oldToNew[originalNode -> random];
        originalNode = originalNode->next;
        cloneNode=cloneNode->next;
    }

    return cloneHead;

}


// Approach 2--> Same as above but done in space Complexity O(1) , we just form a zig-zag list

// O(n) = T.C
// O(1) = S.C

void insertAtTail(Node* &head, Node* &tail ,int d){

    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }


}

Node* copyList(Node* head){
    // Step1: create a clone list

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp!= NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }

    // step2: cloneNodes add in between original list

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode -> next;
        originalNode->next = cloneNode;
        originalNode = next;

        // same step for cloneNode

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step3: random pointer copy

    temp = head;

    while(temp != NULL){
        if(temp->next != NULL){
            if(temp->random != NULL){
              temp ->next ->random = temp->random->next;
            }
            else {
                temp->next = NULL
            }
        }
        temp = temp->next->next;
    }

    // step4: revert changes done in step2

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        cloneNode->next = originalNode->next;
        cloneNode = cloneNode->next;
    }


    // step5: return ans;
    return cloneHead;
}