// O(N) T.C
// O(N) S.C

void inorder(node* root, vector<node*> &in){
        if(root == NULL)
            return ;
        
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
}


node* flatten(node* root){
     vector<node*> inorderVal;
    inorder(root, inorderVal);
    
    int n = inorderVal.size();

    node* newRoot = inorderVal[0];

    // 2nd step
    for(int i=0; i<n-1; i++){
        inorderVal[i]->left = NULL;
        inorderVal[i]->right = inorderVal[i+1];
    }

    // 3rd step

    inorder[n-1]->left = NULL;
    inorder[n-1] -> right = NULL;

    return newRoot;
}
