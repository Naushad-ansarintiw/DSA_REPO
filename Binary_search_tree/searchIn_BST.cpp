bool searchInBST(node* root, int x){
    // base case

    if(root == NULL){
        return false;
    }

    if(root->data == x)
        return true;

    if(root->data > x){
        // left part me
        return searchInBST(root->left, x);
    }
    else {
        // right part me
        return searchInBST(root->right, x);
    }
}