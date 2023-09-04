  class Solution {
    vector<int> inorderTraversal(Node* root){
        stack<Node*> st;
        Node* node = root;
        vector<int> inorder;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node);
                node = node->right;
            }
        }
        return inorder;
    }
};

// T.C O(n) S.C O(n) in worst case space complexity