class Solution{
    public:
    int maxPathSum(Node* root){
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    int maxPathDown(Node* node, int &maxi){
        if(node == NULL) return 0;

        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, leftSum+rightSum+node->val);
        return node->val + max(leftSum, rightSum);
    }
};