// T.C O(n^2) --> but we can reduce to O(nlogn) if we use map to find the position 
class Solution {
    public: 

        int findPosition(int in[], int element, int size){
           for (int i = 0; i < size; i++)
           {
            if(in[i] == element)
                return i;
           }
           return -1;   
        }

        Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int size){
            // base case
            if(index >= size || inorderStart > inorderEnd){
                return NULL;
            }

            // create a root node
            int element = pre[index++];
            Node* root = new Node(element);
            int position = findPosition(in, element, n);

            // recursive call
            root->left = solve(in[], pre[],index, inorderStart, position-1,size);
            root->right = solve(in[], pre[],index, position+1, inorderEnd,size);

            return root;
        }

        Node* buildTree(int in[], int pre[], int n){
            int preOrderIndex = 0;
            Node* ans=solve(in, pre, preOrderIndex, 0, n-1,n);
            return ans;
        }
}