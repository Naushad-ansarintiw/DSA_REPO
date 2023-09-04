class Solution {
    pubic:
        Node* reverseKGroup(Node* head, int k){
            if( head == NULL || k == 1) return head;
            Node* dummy = new Node(0);
            dummy->next = head;

            Node* cur = dummy , *nex = dummy, *pre = dummy;
            int count = 0;

            while(cur->next != NULL){
                cur = cur->next; 
                count++;
            }

            while(count >= k){
                cur = pre->next;
                nex = cur->next;

                for(int i=1; i<k; i++){
                    cur->next = nex->next;
                    nex->next = pre->next;
                    pre->next = nex;
                    nex = cur->next;
                }
                pre = cur;
                count-=k;
            }
            return dummy->next;
        }
};