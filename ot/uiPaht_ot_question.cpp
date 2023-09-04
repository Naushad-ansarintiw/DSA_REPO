// Find the all path in a graph that sum is even 

    //     1
    //    / \
    //   2   3
    //      / \
    //     4   5 
// so all path is 5 in above example
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

vector<int> dfs(int node, vector<vector<int>> &adj, int V, vector<int> &vis) {
    vis[node] = 1;
    vector<int> temp;
    

    for (auto it : adj[node]) {
        if (!vis[it]) {
            vector<int> val = dfs(it, adj, V, vis);
            for (auto it : val) temp.push_back(it);
        }
    }

    if (temp.size() == 0) {
        if (node != 0 && node % 2 == 0) cnt += 1;
        return {node};
    }

    for (auto it : temp) {
        if ((node + it) % 2 == 0) cnt += 1;
    }

    if (node % 2 == 0) cnt += 1;
    for (int i = 0; i < temp.size(); i++) temp[i] += node;
    temp.push_back(node);
    return temp;
}

void calculateMinEvenPath(vector<vector<int>> &adj, int V) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            vector<int> temp = dfs(i, adj, V, vis);
        }
    }
}

int main() {
    int n = 9;
    vector<vector<int>> vec(n);

    vec[1].push_back(2);
    vec[1].push_back(3);

    vec[3].push_back(4);
    vec[3].push_back(5);
    
    vec[6].push_back(7);
    vec[6].push_back(8);

    calculateMinEvenPath(vec, n);
    cout << cnt << " Value" << endl;
    return 0;
}