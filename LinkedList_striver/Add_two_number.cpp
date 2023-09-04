class Solution {
    public:
        Node* addTwoNumbers(Node* l1, Node* l2){
            Node* dummy = new Node();
            Node* temp = dummy;
            int carry = 0;
            while(l1 != NULL || l2 != NULL || carry) {
                int sum = 0;
                if(l1 != NULL){
                    sum += l1->val;
                    l1 = l1->next;
                }
                if(l2 != NULL){
                    sum += l2->val;
                    l2 = l2->next;
                }
                sum += carry;
                carry = sum/10;
                Node* node = new Node(sum%10);
                temp->next = node;
                temp = temp->next;
            }
            return dummy->next;
        }
};