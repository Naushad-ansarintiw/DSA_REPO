class Solution {
    bool isSymmetric(Node* root) {
        return root==NULL || isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(Node* left, Node* right) {
        if(left == NULL || right == NULL)
            return left==right;
        if(left->val != right->val) return false;
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};