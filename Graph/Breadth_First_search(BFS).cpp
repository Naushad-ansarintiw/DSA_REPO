// S.C O(n)
// T.C O(n) + O(2*E) 2*E: is total degree of graph

class Solution {
    public:
        // Functions to return the Breadth First Traversal of given graph structure;
        vector<int> bfsOfGraph(int V, vector<int> adj[]){
            int vis[n] = {0};
            vis[0] = 1;
            queue<int> q;
            q.push(0);
            vector<int> bfs;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push(node);
                
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            return bfs;
        }
}