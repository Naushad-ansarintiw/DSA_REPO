
class DisjoinSet {
    vector<int> rank, parent;
public:
    DisjoinSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i]=i;
        }
    }

    // Path Compression and FindUltimateParent
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];                
            }
        }
};


class Solution {
    public: 
        vector<vector<string>> mergeDetails(vector<vector<string>> & details){
            int n = details.size();
            DisjoinSet ds(n);
            unordered_map<string, int> mapMailNode;
            for(int i=0 ; i<n ; i++){
                for(int j=1; j<details[i].size(); j++){
                    string mail = details[i][j];
                    if(mapMailNode.find(mail) == mapMailNode.end()){
                        mapMailNode[mail] = i;
                    }
                    else {
                        ds.unionBySize(i, mapMailNode[mail]);
                    }
                }
            }

            vector<string> mergedMail[n];
            for(auto it: mapMailNode){
                string mail = it.first;
                int node = ds.findUPar(it.second);
                mergedMail[node].push_back(mail);
            }

            vector<vector<string>> ans;
            for(int i=0; i<n; i++){
                if(mergedMail[i].size() == 0) continue;
                sort(mergedMail[i].begin(), mergedMail[i].end());
                vector<string> temp;
                temp.push_back(details[i][0]);
                for(auto it: mergedMail[i]){
                    temp.push_back(it);
                }
            }
          return ans;
        }
};