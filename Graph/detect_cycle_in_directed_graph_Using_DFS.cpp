

class Solution {
    private:
        bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
            vis[node] = 1;
            pathVis[node] = 1;

            // traverse for adjscent nodes
            for(auto it: adj[node]){
                // when the node is not visited
                if(!vis[it]){
                    if(dfsCheck(it, adj, vis, pathVis))
                        return true;
                }
                // if the node is visited
                // but it has to visited on the same paht
                else if(pathVis[it])
                    return true;
            }
            pathVis[node] = 0;
            return false;
        }


    public:
         // fucntion to detect cycle in a directed graph

         bool isCycle(int V, vector<int> adj[]){
            int vis[V] = {0};
            int pathVis[V] = {0};

            for(int i = 0; i < V; i++){
                if(!vis[i]){
                    if(dfsCheck(i, adj, vis, pathVis)) return true;
                }
            }
            return false;
         }
};