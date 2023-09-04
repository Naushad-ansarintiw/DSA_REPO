// // Coding Ninja Question

// Approch 1 --> we take a curr pointer and point to the head+1 and now traverse the whole linked list if we again come to head pointer then it is a circular linked list

// T.C = O(n)
// S.C = O(1)


bool isCircularList(Node* head) {
    // empty NOde case
    if(head == NULL) return true;

    // Check for node>=1 
    Node* temp = head->next;

    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }

    if(temp!=NULL) return true;
    else return false;

}





// Approch 2 --> Using map if visited then return true otherwise return false;
// T.C = O(n)
// S.C = O(n)


class Node {
    public:
        int data;
        Node* next;
};


// Function to create Linked List
// Node
Node* newNode(int d)
{
    Node* temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}

// Declaration of Map to keep
// mark of visited Node
map<Node*, bool> vis;
bool flag = 0;

// Function to check cycle in Linked
// List
void check(Node* head)
{
    // If head is NULL return ;
    if (head == NULL) {
        flag = 0;
        return;
    }
 
    // Mark the incoming Node as
    // visited if it is not visited yet
    if (!vis[head]) {
        vis[head] = true;
        check(head->next);
    }
 
    // If a visited Node is found
    // Update the flag value to 1
    // and return ;
    else {
        flag = 1;
        return;
    }
}

// Driver Code
int main()
{
    // Create a head Node
    Node* head = newNode(20);
 
    // Inserting Node in Linked List
    head->next = newNode(4);
    head->next->next = newNode(5);
    head->next->next->next = newNode(10);
 
    // Just to make a cycle
    head->next->next->next->next = head;

        // Function that detect cycle in
    // Linked List
    check(head);
 
    // If flag is true, loop is found
    if (flag)
        cout << "Loop detected.";
 
    // If flag is false, No Loop
    // detected
    else
        cout << "No Loop Found.";
    cout << endl;
 
    return 0;
}

    return 0;

}