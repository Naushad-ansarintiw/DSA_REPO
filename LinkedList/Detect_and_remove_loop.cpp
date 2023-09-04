// Coding Ninja Question

// Q1 Detect cycle in Linked List 
// Q2 Remove Cycle from Linked List 
// Q3 find Starting node of Loop 

// Approch 1 -->  using map we mark all node and if we found marked node than it has loop in the Linked lIst

// T.C = O(n)
// S.C = O(n)

bool detechLoop(Node* head){
    // If empty List 

    if(head == NULL){
        return NULL;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
  
        // cycle present
        if(visited[temp] == true){
             return 1;
        }
        visited[temp] = true;
        temp = temp->next; 
    }


    return 0;
}


// Aprroch 2 =--> Floyd cycle detection Use to reduce the space Complexity 
// WE take two pointer slow and fast , where slow move one step whereas fast move two step if they fast meet slow then loop is present this is called floyd cycle detection



Node* floydDetectLoop(Node* head){
    // If empty array 
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
          fast = fast->next;
          if(fast != NULL) {
            fast = fast->next;
          } 

          slow = slow->next;

          if(slow == fast) return 1;
    }

    return 0;
}


// Q3 Find Starting node in a loop


// Using floyd cycle detection

Node* getStartingNode(Node* head){

    // If empty array 
    if(head == NULL){
        return false;
    }

    Node* intersection = floydDetection(head);  // getting intersection of slow and fast in a cycle

    Node* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
    
}


// Q2 --> Remove the loop

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
      
    while(temp->next != startOfLoop){
        temp = temp->next;
    }

    temp-next = NULL;
}