// Its work only Directed Graph if Undirected Graph is given we have to convert it into Directed Graph

class Solution {
    public:
        vector<int> bellman_ford(int V, vector<vector<int> > &edges, int S){
            vector<int> dist(V, 1e8);
            dist[S] = 0;
            // T.C V*E
            for(int i=0; i<V-1; i++){
                for(auto it: edges){
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];
                    if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }

            // Nth relaxation to check negative cycles
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    return {-1};
                }
            }

            return dist;
        }
};