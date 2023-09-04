// T.C O(n)
// S.C O(n)

class Solution{
  public:
  
    void inOrder(Node* root, vector<int> &ans){
        // base case 
        if(root == NULL)
            return;
        
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    
    void postOrderHeap(Node* &root, vector<int> &vec, int &currIndex){
        // base case 
        if(root == NULL)
            return; 
        
        postOrderHeap(root->left, vec, currIndex);
        postOrderHeap(root->right, vec, currIndex);
        
        root->data = vec[currIndex++];
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        
        // step1: get the inorder
         vector<int> ans;
         inOrder(root, ans);
         
        
        
        // step 2: convert inorder to postorder
        int initialIndex = 0;
        postOrderHeap(root, ans, initialIndex);
        
    }    
};