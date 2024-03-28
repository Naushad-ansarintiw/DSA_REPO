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

