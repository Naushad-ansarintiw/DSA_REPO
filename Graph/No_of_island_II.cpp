class DisjoinSet
{
    vector<int> rank, parent, size;

public:
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Path Compression and FindUltimateParent
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<int> numofIslands(int m, int n, vector<vector<int>> &operators)
    {
        DisjoinSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;

            int dr[] = {-1, 0, +1, 0};
            int dc[] = {0, +1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int r = row + dr[i];
                int c = col + dc[i];
                if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = r * m + c;
                    if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                    {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
    }

    return ans;
}
}
;