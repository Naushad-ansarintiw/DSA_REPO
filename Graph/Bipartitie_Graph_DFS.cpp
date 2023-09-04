

class Solution {
    // color a individual component of the graph
    private: 
        bool dfs(int node, int col, int color[], vector<int> adj[]){

            color[node] = col;

                for(auto it : adj[node]){
                    // if the adjacent node is yet not colored,
                    // you will give the opposite color of the node
                    if(color[it] == -1){
                       if(dfs(it, !col, color, adj) == false) return false;
                    }
                    // is the adjacent guy having the same color 
                    // someone did color it on some other paht
                    else if(color[it] == color[node]){
                        return false;
                    }
                }
            return true;
        }


    public: 
        bool isBipartite(int V, vector<int> adj[]){
            int color[V];
            for(int i=0;i<V;i++) color[i] = -1;
            for(int i=0;i<V;i++){
                if(color[i] == -1){
                    if(dfs(i,0, color, adj) == false) return false;
                }
            }
            return true;
        }
};