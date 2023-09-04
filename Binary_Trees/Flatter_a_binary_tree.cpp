// T.C O(n)
// S.C O(1)

class Solution{
    public:
        void flatten(Node* root){
            Node* curr = root;
            while(curr != NULL){
                if(curr->left){
                    Node* predesser = curr->left;
                    while(predesser->right) 
                        pred = pred -> right;
                    
                    pred->right = curr->right;
                    curr -> right = curr->left;
                    curr -> left = NULL;
                }
            curr = curr -> right;
            }
        }
}