// T.C O(n^2)
class Solution {
    private:
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
    public:
        bool isBalanced(Node* root){
            // base case
            if(root == NULL){
                return true;
            }

            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);

            bool diff = abs(height(root->left) - height(root->right)) <= 1;

            if(left && right && diff) {
                return true;
            }
            else {
                return false;
            }
        }
}


// Approch 2 to return pair 

// O(n) T.C

public: 

    pair<bool,int> isBalancedFast(Node* root){
        // base case
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root-> right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else {
            ans.second = false;
        }
        return ans;
    }