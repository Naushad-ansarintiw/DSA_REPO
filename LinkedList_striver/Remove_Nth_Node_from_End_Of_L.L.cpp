// 1st method just count the length of ll

// T.C O(2*n)

class Solution {
    public:
        Node* removeNthFromEnd(Node* head, int n){
            Node* dummy = head;
            int cnt = 0;
            while(dummy != NULL){
                dummy = dummy->next;
                cnt++;
            }
            int stepMoveBegin = cnt-n;

            if(stepMoveBegin) {
             dummy = head;
            while(stepMoveBegin > 1){
                dummy = dummy->next;
                stepMoveBegin--;
            }

            Node* removalNode = dummy->next;
            dummy->next = removalNode->next;
            delete removalNode;
            return head;
            }
            else return head->next;
        }
};

// 2nd method fast and slow pointer;

// T.C O(n)

class Solution {
    public:
        Node* removeNthFromEnd(Node* head, int n){
            ListNode* start = new ListNode();
            start->next = head;
            ListNode* fast = start;
            ListNode* slow = start;

            for(int i=1; i<=n; i++)
                fast = fast->next;
            
            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }

};


