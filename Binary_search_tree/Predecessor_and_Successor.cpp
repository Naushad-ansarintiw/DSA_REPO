// T.C O(n)
// S.C O(1)

pair<int,int> predecessorSuccessor(Node* root, int key){
    
    // find key 

    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // pred and succ

    // pred nikalna hai jo ki hamesha left subtree me hoga
     Node* leftTree  = temp -> left;

     while(leftTree != NULL){
        pred = leftTree -> data;
        leftTree = leftTree->right;
     }

    // succ nikalna hai jo ki hamesha right subtree me hoga
     Node* rightTree = temp -> right

     while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
     }
    
    pair<int,int> ans = make_pair(pred,succ);
    return ans;
}