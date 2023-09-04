class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    private:    
        void dfs3(int node, vector<int> &vis, vector<int> adjT[]){
            vis[node] = 1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs3(it, vis, adj);
                }
            } 
        }
    public:     
        int kosaraju(int V, vector<int> adj[]){
            vector<int> vis(V, 0);
            stack<int> st;
            // 1 step: store the node in order to there finishing time 
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    dfs(i, vis, adj, st);
                }
            }
            // 2 step: Do reverse the graph
            vector<int> adjT[V];
            for(int i=0; i<V; i++){
               for(auto it: adj[i]) {
                 // edge i->it
                 // reverse edge it->i
                 adjT[it].push_back(i);
               }
            }
            // clear vis array
            vis.assign(V, 0);
            int scc = 0;
            while(!st.empty()) {
                int node = st.top();
                st.pop();
                if(!vis[node]){
                    scc++;
                    dfs3(node, vis, adjT);
                }
            }
            return scc;
        }
}