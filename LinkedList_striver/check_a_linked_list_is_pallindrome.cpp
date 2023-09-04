class Solution{
    public:
        bool isPallindrome(Node* head){
            if(head==NULL && head->next == NULL) return true;

            Node* slow = head;
            Node* fast = head;

            // finding the middle of the L.l
            while(fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            slow->next = reverseList(slow->next);
            slow = slow->next;

            while(slow != NULL){
                if(head->val != slow->val) return false;
                head = head->next;
                slow = slow->next;
            }
            return true;
        }

        Node* reverseList(Node* head){
            Node* pre = NULL;
            Node* next = NULL;
            while(head != NULL){
                next = head->next;
                head->next = pre; 
                pre = head;
                head = next;
            }
            return pre;
        }
};