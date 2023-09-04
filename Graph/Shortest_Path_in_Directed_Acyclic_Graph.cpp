

class Solution {
    private:
        void dfstopoSort(int node, vector<pair<int, int> > adj[], int vis[], stack<int> &st){
            vis[node] = 1;
            for(auto it: adj[node]){
               int v = it.first;
               if(!vis[v]){
                dfstopoSort(v, adj, vis, st);
               } 
            }
            st.push(node);
        }

    public:
        vector<int> shortestPath(int N, int M, vector<int> egdes[]){
            vector<pair<int, int> > adj[N];
            for(int i = 0; i < M; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                adj[u].push_back({v,wt});
            }

            //step1: find the topo sort
            int vis[N] = {0};
            stack<int> st;
            for(int i = 0; i < N; i++){
                if(!vis[i]){
                    dfstopoSort(i, adj, vis, st);
                }
            }

            // step2: do the distance thing
            vector<int> dist[N];
            for(int i = 0; i < N; i++) dist[i] = INT_MAX;
            dist[0] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();

                for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt  < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
            return dist;
        }
};