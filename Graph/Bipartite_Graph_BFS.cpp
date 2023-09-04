// Q1. What is Bipartite Graph?
// ANs: Color the graph with 2 colors such that no adjacent nodes have same color.

// ObServation 
// 1.Linear graph with no cycles have always Bipartite graph
// 2.Any graph with even cycles length are always Bipartite graph
// 3.Any graph with odd cycles length are never be Bipartite graph


class Solution {
    // color a individual component of the graph
    private: 
        bool check(int start, int V, vector<int> adj[], int color[]){
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    // if the adjacent node is yet not colored,
                    // you will give the opposite color of the node
                    if(color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    // is the adjacent guy having the same color 
                    // someone did color it on some other paht
                    else if(color[it] == color[node]){
                        return false;
                    }
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
                    if(check(i,V, adj, color)== false) return false;
                }
            }
            return true;   
        }
};