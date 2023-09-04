// Coding Ninja Question

// Time Complexity = O(n);
// Space Complexity = O(1);

// Approach 1 using a traversal a linked List
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node *prev = NULL;
  Node *curr = head;
  Node *forward = NULL;

  while (curr != NULL)
  {
    forward = curr->next;

    curr->next = prev;
    prev = curr;
    curr = forward;
  }

  return head;
}

// Approch 2 using a recursion

// Time Complexity --> O(n);


void solve(Node* &head,Node* curr,Node* prev) {
   
   // Base Case 
   if(curr == NULL) {
    head = prev;
    return head;
   }

   Node* forward = curr->next;
   solve(head , forward , curr);
   curr->next = prev;
}


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{

  Node *prev = NULL;
  Node *curr = head;
  solve(head, curr, prev);
  return head;
}