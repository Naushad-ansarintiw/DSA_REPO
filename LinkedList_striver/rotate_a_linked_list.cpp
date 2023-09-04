class Solution{
    Node* rotateRight(Node* head,int k){
        // edge case
        if( !head || !head->next || k == 0 ) return head;
        
        // compute lenght
        Node* cur = head;
        int len = 1;
        while(cur->next && ++len) cur = cur->next;

        // go till that node
        cur->next = head;
        k = k%len;
        k = len - k;
        while(k--) cur = cur->next;

        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};