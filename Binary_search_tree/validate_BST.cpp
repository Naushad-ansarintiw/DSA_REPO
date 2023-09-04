// T.C O(N)
// S.C O(Height of tree);
bool isBST(Node* root, int min, int max) {

    // base case
    if(root == NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right,root->data, max);
        return left && right;
    }
    else {
        return false;
    }
}


bool isValidate(Node* root){
    return isBST(root, INT_MIN, INT_MAX);
}           