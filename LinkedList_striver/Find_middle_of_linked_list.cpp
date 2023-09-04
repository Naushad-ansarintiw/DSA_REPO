// approach tortuise approack slow and fast pointer;

class Solution {
    public:
        Node* middleNode(Node* head){
            Node* slow = head, fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};