//T.C O(N)
void inorder(BinaryTreeNode<int>* root, int &count) {
    // base case
    if(root == NULL){
        return ;
    }

    inorder(root->left,count);
    inorder(root->right,count);
    // leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

}

int noOfLeafNodes(BinaryTreeNode<int> *root) {


    int cnt = 0;
    inorder(root,cnt);
    return cnt;

}