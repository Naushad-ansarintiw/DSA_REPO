// Inplace Approach --> Not use any external Linked List 

class Solution{
    public:
        Node* mergeTwoLists(Node* l1, Node* l2){
            // iterative
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;
            if(l1->val > l2->val) swap(l1,l2);
            Node* resultant = l1;
            while(l1 != NULL && l2 != NULL){
                Node* temp = NULL;
                while(l1 != NULL && l1->val <= l2->val){
                    temp = l1;
                    l1 = l1->next;
                }
                temp->next = l2;
                swap(l1,l2);
            }
            return resultant;
        }
};