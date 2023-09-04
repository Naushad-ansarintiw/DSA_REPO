
class Solution {
    public:
        int spanningTree(int V, vector<vector<int>> adj[]){
            // S.C O(E)
            priority_queue<pair<int,int>, vector<pair<int,int> > , greater<piar<int,int> > > pq;
            
            vector<int> vis(V, 0);
            // {wt, node}
            pq.push({0,0});
            int sum = 0;
            
            // E*logE + E*logE
            // E*logE
            while(!pq.empty()){

                // logE
                auto it = pq.top();
                pq.pop();

                int node = it.second;
                int wt = it.first;

                if(vis[node] == 1) continue;
                // add it to the mst
                vis[node] = 1;
                sum += wt;

                // E*logE
                for(auto it: adj[node]){
                    int adjNode = it[0];
                    int edW = it[1];

                    if(!vis[adjNode]) {
                        pq.push({edW, adjNode});
                    }
                }
            }
            return sum; 
        }
};