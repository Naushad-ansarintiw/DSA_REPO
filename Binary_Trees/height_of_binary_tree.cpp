// O(n) T.C
// O(heighT) S.C
class Solution{
    public:
        int height(struct Node* node){
            // base case
            if(root == NULL){
                return 0;
            }

            int left = height(node->left);
            int right = height(node->right);

            int ans = max(left , right) +1;
            return ans;
        }
}