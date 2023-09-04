class Solution {
   private:
    vector<int> rightSideView(Node* root){
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
    public:
        void recursion(Node* root, int level, vector<int>& res){
            if(root == NULL) return ;
            if(res.size()==level) res.push_back(root->val);
            recursion(root->right, level+1, res);
            recursion(root->left, level+1, res);
        }
};