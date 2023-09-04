// T.C O(nlogn)
class Solution {
    public: 

    // Mapping that give elemeent index

    void createMapping(int in[], map<int,int> & nodeToIndex, int n){
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]]= i;
        } 
    }

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int size){
        // base case
        if(index < 0|| inorderStart > inorderEnd){
            return NULL;
        }
        // create a root node
        int element = pre[index--];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);

        // recursive call [In case of Postorder and inorder , we first build right sub tree]
        root->right = solve(in, post,index, position+1, inorderEnd,size);
        root->left = solve(in, post,index, inorderStart, position-1,size);
    }

        Node* buildTree(int in[], int post[], int n){
            int postOrderIndex = n-1;
            map<int,int> nodeToindex;

            // create nodes to index mapping 
            createMapping(in, nodeToindex, n)

            Node* ans=solve(in, post, postOrderIndex, 0, n-1,n);
            return ans;
        }
}