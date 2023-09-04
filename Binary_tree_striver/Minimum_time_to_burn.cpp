class Solution{
    private:
        int findMaxDistance(unordered_map<Node*, Node*> &parent_track,  Node* target){
            queue<Node* > q;
            q.push(target);
            map<Node*, bool > vis;
            int maxi = 0;
            while(!q.empty()){
                int sz = q.size();
                int fl = 0;
                for(int i = 0; i < sz; i++){
                    auto node = q.front();
                    q.pop();
                    if(node->left && !vis[node->left]){
                        fl = 1;
                        vis[node->left] = true;
                        q.push(node->left);
                    }
                    if(node->right && !vis[node->right]){
                        fl = 1;
                        vis[node->right] = true;
                        q.push(node->right);
                    }
                    if(mpp[node] && !vis[mpp[node]]){
                        fl = 1;
                        vis[mpp[node]] = true;
                        q.push(mpp[node]);
                    }
                }
                if(fl) maxi++;
            }
            return maxi;
        }

        Node* markParents(Node* root, unordered_map<Node*, Node*> &parent_track, int start){
            queue<Node*> queue;
            queue.push(root);
            Node* res;
            while(!queue.empty()){
                Node* current = queue.front();
                if(current->data == start) res = node;
                queue.pop();
                if(current->left){
                    parent_track[current->left] = current;
                    queue.push(current->left);
                }
                if(current->right){
                    parent_track[current->right] = current;
                    queue.push(current->right);
                }
            }
        }
    public:
        int timeToBurnTree(Node* root, int start){
            unordered_map<Node*, Node*> parent_track; // node-->parent
           Node* target = markParents(root, parent_track,start);

            int maxi = findMaxDistance(parent_track, target);
            return maxi;
        }
};