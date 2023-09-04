// Approch 1 --> traverse all the linked list and count how many 0s 1s 2s and now again traverse and set

// O(n) -> T.C
// O(1) -> S.C

Node* sortList(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = NULL;
    while(temp != NULL){
        if(temp->data == 0 ){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++
        }

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }
    return head;
}



// Approach 2 -> Now change the links make three L.L Zero , One, Two if zero occurs in main L.L then add zero in Zero L.L and soon

// O(n) -> T.C
// O(1) -> S.C


void insertAtTail(Node* &tail, Node* curr){

    tail -> next  = curr;
    tail = curr;
}


Node* sortList(Node* head){
    
    Node* zeroHead = new Node(-1);
    Node* zeorTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead
    Node* twoHead = new Node(-1);
    Node* twoTail =  twoHead;

    Node* curr = head;


   // Create sepaarte list 0s, 1s , 2s
    while(curr != NULL){
        int value = curr->data;
        
        if(value == 0){
            insertAtTail(zeroTail,curr);
        }
        else if(value == 1){
            insertAtTail(oneTail,curr);
        }
        else if(value == 2){
            insertAtTail(twoTail,curr);
        }

        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty 
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else {
        // 1s list empty
        zeroTail ->next = twoHead->next;
    }

    oneTail -> next = twoHead->next;
    twoTail -> next = NULL;


    // setup head 
    head = zeroHead -> next;

    // delete dummy nodes 
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}