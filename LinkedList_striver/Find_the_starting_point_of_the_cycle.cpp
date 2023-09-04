class Solution {
    public: 
    Node* detectCycle(Node *head){
        if(head == NULL || head->next == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;
        Node* entry = head;

        // move until the find the collision point
        while(fast -> next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == next){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
       return NULL;
    }
};