class Solution{
    public: 
      Node* reverseList(Node* head){
        Node* newHead = NULL;
        while(head != NULL){
            Node *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
      }
};