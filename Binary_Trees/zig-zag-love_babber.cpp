//T.C O(n)
// S.C o(n)

class Solution{
    public:
        vector<int> zigzagTraversal(Node* root){
            vector<int> ans;
            if(root == NULL){
                return ans;
            }

            queue<Node*> q;
            q.push(root);

            bool leftToRight = true;

            while(!q.empty()){
                int size = q.size();
                vector<int> arr(size);
                // level process
                for(int i = 0 ;i<size;i++){
                    Node* frontNode = q.front();
                    q.pop();

                    // normal inser of reverse insert
                    int index = leftToRight ? i : size-i-1;
                    arr[index] = frontNode -> data;

                    if(frontNode -> left)
                        q.push(frontNode -> left);
                    if(frontNode -> right)
                        q.push(frontNode -> right);
                }

                // direction change karne h
                leftToRight = !leftToRight;

                for(auto i: ans){
                    ans.push_back(i);
                }

            }
            return ans;
        }
};