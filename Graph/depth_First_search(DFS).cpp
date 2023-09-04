// S.C O(N)
// T.C O(N)+O(2*E) // E: no. of edges

class Solution {
    private:
       void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbors
        for(auto it: adj[node]){
            // if neighbor is not already visited
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            } 
        } 
       }
    public:
        // function to return a list of containing solution of the DFS traversal of the graph
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            int vis[V] = {0};
            int start = 0;
            vector<int> ls;
            dfs(start, adj, vis, ls);
            return ls;
        }
}