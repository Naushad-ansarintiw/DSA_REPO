vector<ll> edges[150005];
ll label[150005]; // current components of each vertex
ll sz[150005]; // size of each components
ll nedges[150005]; // no of edges in each components

void relabel(ll v, ll target){
  if(label[v] == target) return;
  label[v] = target;

  for(ll x: edges[v]){
      relabel(x, target);
  }
}

void merge(ll u, ll v) {
  edges[u].push_back(v);
  edges[v].push_back(u);

  ll cu = label[u], cv = label[v];
  ++nedges[cu];
  
  if(cu == cv) return;

  if(sz[cu] > sz[cv]) {  
      swap(u, v);
      swap(cu, cv);
  }
  // assume sz[cu] <= sz[cv]

  relabel(u, cv);

  sz[cv] += sz[cu];
  nedges[cv] += nedges[cu];
}


// Important Note  Before using this initialize this
// for(ll i=0; i<n; i++) {
//     sz[i] = 1;label[i] = i; 
// }



------------------------------striver-----------------------------------
  class DisjointSet {
        vector<int> rank, size, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank(int u, int v) {
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
        
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            
        }
};
