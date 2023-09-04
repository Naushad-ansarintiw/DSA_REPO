// T.C O(n)

Node* LCAinaBST(Node* root, Node* P, Node* Q){
    // base case 

    if(root == NULL)
        return NULL;

    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, O);
    }

    if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, O);
    }

    return root;
}