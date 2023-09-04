int solve(Node* root, int &i, int k){
    // base case 
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k);
    if (left != -1){
        return left;
    }
    // Stand at N
    i++;
    if(i==k){
        return root->data;
    }

    // R
    return solve(root->right,i, k);
}


int kthSmallest(Node* root, int k){
    int i=0;
    int ans = solve(root, i, k);
    return ans;
}