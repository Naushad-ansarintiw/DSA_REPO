class Solution{
    public:
        int diameterOfBinaryTree(Node* root){
            int diameter = 0;
            return height(root, diameter);
        }

    private:
        int height(Node* node, int& diameter){
            if(!node) return 0;

            int lh = height(node->left, diameter);
            int rh = height(node->right, diameter);
            diameter = max(lh, rh);
            return 1 + max(lh,rh);
        }
};