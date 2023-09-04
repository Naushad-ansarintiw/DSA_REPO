class Solution{
    public:
        int countNodes(Node* root){
            if(root == NULL) return 0;

            int lh = findHeightLeft(root);
            int rh = findHeightRight(root);
            if(lh == rh) return (1<<lh)-1;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

        int findHeightLeft(Node* node){
            int hght = 0;
            while(node){
                hght++;
                node = node->left;
            }
            return hght;
        }

        int findHeightRight(Node* node){
            int hght = 0;
            while(node){
                hght++;
                node = node->right;
            }
            return hght;
        }
};