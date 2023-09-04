class Solution {
    private:
        void markParents(Node* root, unordered_map<Node*, Node*> &parent_track, Node* track){
            queue<Node*> queue;
            queue.push(root);
            while(!queue.empty()){
                Node* current = queue.front();
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
        vector<int> distanceK(Node* root, Node* target, int k){
            unordered_map<Node*, Node*> parent_track; // node-->parent
            markParents(root, parent_track, target);

            unordered_map<Node*, bool> visited;
            queue<Node*> q;
            q.push(target);
            visited[tartget] = true; 
            int cur_level = 0;
            while(!q.empty()){ /* second BFS to go upto K level from target node and usning our hashtable*/
            int size = q.size();
            if(curr_level == k) break;
            curr_level++;
            for(int i = 0; i < size; i++){
                Node* current = q.front(); q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            }
            vector<int> result;
            while(!q.empty()){
                Node* curr = q.front(); q.pop();
                result.push_back(curr->val);
            }
            return result;
        }
};