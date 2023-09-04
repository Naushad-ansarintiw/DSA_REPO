//If a cycle is in graph then we can't produce its toposort beacause TopoSort only Works for Directed Acyclic Graph (DAG).

class Solution {

    public: 
    bool isCyclic(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
         queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
               q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() == V) return false;
        else return true;   
    }
};