// T.C O(n)
// S.C o(h)

int countNode(Node* root){
    // base case
    if(root == NULL)    
        return 0;
    
    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}


bool isCBT(Node* root, int index, int cnt){
    if(root==NULL)
        return true;
    
    if(index >= cnt)
        return false;
    else{
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);

        return (left && right);
    }
}

bool isMaxorder(Node* root){
    // base case 
    if(root->left == NULL && root->right == NULL)
        return true;

    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    } else {
        bool left = isMaxorder(root->left);
        bool right = isMaxorder(root->right);
        return (left && right && (root->data > root->left->data) && (root->data >));
    }
}



bool isHeap(Node* root){

    int index = 0;
    int totalCount = countNode(root);
    if( isCBT(root, index, totalCount ) && isMaxOrder(root))
        return true;
    else 
        return false;
}