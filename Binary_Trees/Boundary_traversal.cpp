// T.C O(n)
// S.C O(height)
class Solution {
    public: 
        void traverseLeft(Node* root, vector<int> &ans){
                // base case
                if((root == NULL) || (root->left == NULL && root->right == NULL))
                    return ;
                
                ans.push_back(root->data);

                if(root->left)
                    traverseLeft(root->left);
                else        
                    traverseLeft(root->right);
        }
        
        void traverseLeaf(Node* root, vector<int> &ans){
            // base case
            if(root == NULL)
                return ;
            
            if(root->left == NULL && root->right == NULL){
                ans.push_back(root->data);
                return ;
            }

            traverseLeaf(root->left,ans);
            traverseLeaf(root->right,ans);
        }

        void traverseRight(Node* root, vector<int> ans){
            // base case
                if((root == NULL) || (root->left == NULL && root->right == NULL))
                    return ;

                // using backtraking 

                if(root->right){
                    traverseRight(root->right,ans);
                }
                else{
                    traverseReft(root->left,ans);
                }

                // wapas aagye 
                ans.push_back(root->data,ans);
        }

     vector<int> boundary(Node* root){
            vector<int> ans;
            
            // base case
            if(root == NULL){
                return ans;
            }

            ans.push_back(root->data); 

            // left part store
            traverseLeft(root->left,ans);

            // traverse Leaf Nodes
            
            // left subtree
            traverseLeaf(root->left,ans);
            // right subtree
            traverseLeaf(root->right,ans);

            // traverse right part
            traverseRight(root->right,ans);

        }
}