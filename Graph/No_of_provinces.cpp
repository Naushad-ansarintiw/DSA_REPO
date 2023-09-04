// S.C O(N)
// T.C O(V) + O(V+2*E)

class Solution {
    private:
        void dfs(int node, vector<int> &adjLs[], vector<int> vis){
            vis[node] = 1;
            for(auto it: adjLs[node]){
                if(!vis[it]){
                    dfs(it, adjLs, vis);
                }
            }
        }

    public:
        int numProvinces(vector<vector<int> > adj, int V){
             vector<int> ls[V];

            // to change the adjacency matrix to list/vector
             for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    if(adj[i][j] && i != j){
                        ls[i].push_back(j);
                        ls[j].push_back(i);
                    }
                }
             }
 
             int vis[V] = {0};
             int cnt = 0; 

            // checking the number of provinces
             for(int i = 0; i < V; i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i, ls, vis);
                }
            }
            return cnt;
        }
};