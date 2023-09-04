

node* solve(vector<int> &preorder, int mini , int maxi, int &i){
    // base casse
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini && preorder[i] > maxi)
        return NULL;

    node* root= new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;

}

node* preOrderToBST(vector<int> &preorder){

    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;
    solve(preorder, mini, maxi, i);

}