#include <bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
    int n, LOG;
    vector<vector<int>> up;  // Binary lifting table
    vector<int> depth;       // Depth of each node

    void dfs(int node, int parent, const vector<vector<int>>& adj) {
        up[0][node] = parent;
        for (int i = 1; i <= LOG; ++i) {
            if (up[i-1][node] != -1) {
                up[i][node] = up[i-1][up[i-1][node]];
            }
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, node, adj);
            }
        }
    }

public:
    BinaryLifting(int _n) : n(_n) {
        LOG = log2(n) + 1;
        up.assign(LOG + 1, vector<int>(n, -1));
        depth.assign(n, 0);
    }

    void preprocess(int root, const vector<vector<int>>& adj) {
        dfs(root, -1, adj);
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= LOG; ++i) {
            if (k & (1 << i)) {
                node = up[i][node];
                if (node == -1) break;
            }
        }
        return node;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        u = getKthAncestor(u, diff);

        if (u == v) return u;

        for (int i = LOG; i >= 0; --i) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }
        return up[0][u];
    }

    int getDepth(int node) {
        return depth[node];
    }
};

int main() {
    int n; // Number of nodes
    cin >> n;
    vector<vector<int>> adj(n);

    // Read edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Assuming 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BinaryLifting bl(n);
    int root = 0; // Assuming the root is node 0
    bl.preprocess(root, adj);

    // Example queries
    int u, v;
    cin >> u >> v;
    u--; v--; // Assuming 0-based indexing
    cout << "LCA of " << u + 1 << " and " << v + 1 << " is " << bl.lca(u, v) + 1 << endl;

    int node, k;
    cin >> node >> k;
    node--; // Assuming 0-based indexing
    int ancestor = bl.getKthAncestor(node, k);
    if (ancestor == -1) {
        cout << "No " << k << "-th ancestor for node " << node + 1 << endl;
    } else {
        cout << k << "-th ancestor of node " << node + 1 << " is " << ancestor + 1 << endl;
    }

    return 0;
}
