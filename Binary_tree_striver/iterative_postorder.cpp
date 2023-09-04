// Approch 1 using 2 stack

class Solution{
    public:
        vector<int> postOrderTraveral(Node* root){
            vector<int> postOrder;
            if(root == NULL) return postOrder;
            stack<Node*> st1, st2;
            st1.push(root);
            while(!st1.empty()){
                root = st1.pop();
                st1.pop();
                st2.push(root);
                if(root->left != NULL) st1.push(root->left);
                if(root->right != NULL) st1.push(root->right);
            }
            while(!st2.empty()){
                postOrder.push_back(st2.top()->val);
                st2.pop();
            }
            return postOrder;
        }
};



 