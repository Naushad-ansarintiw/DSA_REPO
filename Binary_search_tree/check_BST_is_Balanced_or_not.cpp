// O(N) T.C
// O(N) S.C

void inorder(node* root, vector<int> &in){
        if(root == NULL)
            return ;
        
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
}

node* inorderToBST(int s,int e, vector<int> &in){
    // base case
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;

    node* root = new node(in[mid]);

    root->left = inorderToBST(s,mid-1, in);
    root->right = inorderToBST(mid+1,e, in);

    return root;

}

node* balancedBst(node* root){
     vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBST(0,inorderVal.size()-1, inorderVal);
}