class Solution {
    private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it] == 0){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>  &vis, vector<int> revadj[]){
        vis[node] = 1;
        for(auto it: revadj[node]){
            if(vis[it] == 0){
                dfs3(it, vis, revadj);
            }
        }
    }

    publlic:
        int kosoraju(int V, vector<int> adj[]){
            vector<int> vis(V,0);
            stack<int> st;
            // step1 store all the nodes in the order of finishing time
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    dfs(i,vis,adj,st);
                }
            }

            // step2 reverse all the edges of the graph
            vector<int> revadj[V];
            for(int i=0; i<V; i++){
                vis[i] = 0; // for reuse perpose
                for(auto it: adj[i]){
                    // i-->it
                    // reverse it-->i
                    revadj[it].push_back(i);
                }
            }

            // step3; perform the dfs but in the order of finishing time
            int scc = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                if(!vis[node]){
                    scc++;
                    dfs3(node, vis, revadj);
                }
            }
          return scc;
        }
};