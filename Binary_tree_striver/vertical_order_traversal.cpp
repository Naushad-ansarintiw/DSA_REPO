class Solution {
    public:
        vector<vector<int>> verticalTraversal(Node* root){
            map<int, map<int, multiset<int>>> nodes;
            queue<pair<Node*, pair<int, int>>> todo;
            todo.push({root,0,0});
            while(!todo.empty()) {
                auto p = todo.front();
                todo.pop();
                Node* node = p.first;
                int vertical = p.second.first, level = p.second.second;
                nodes[x][y].insert(node->val);
                if(node -> left){
                    todo.push({node->left, {vertical-1, level+1}});
                }
                if(node -> right){
                    todo.push({node->right, {vertical+1, level + 1}});
                }
            }
            vector<vector<int>> ans;
            for(auto p: nodes){
                vector<int> col; 
                for(auto q: p.second){
                    col.insert(col.end(), q.second.begin(), q.second());
                }
                ans.push_back(col);
            }
            return ans;
        }
};