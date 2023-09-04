class Solution{
    vector<int> preorderTraversal(Node* root){
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
        }
        return preorder;
    }
};