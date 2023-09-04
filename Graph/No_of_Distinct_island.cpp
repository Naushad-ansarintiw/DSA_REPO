class Solution {
    private:
        void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0, int n, int m){
            vis[row][col] = 1;
            // row0--> base row simillarly col0 --> base col 
            vec.push_back(make_pair(row-row0, col-col0));
            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, +1, 0, -1};
            for(int i = 0; i < 4; i++){
                int r = row + delrow[i];
                int c = col + delcol[i];
                if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && vis[r][c] == 0){
                    dfs(r, c, grid, vis, vec, row0, col0,n,m);
                }
            }
        }

        }
    public:
        int countDistinctIslands(vector<vector<int>> & grid){
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m,0));
            set<vector<pair<int, int> > > st;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int> > vec;
                    dfs(i, j, grid, vis, vec, i, j, n, m);
                    st.insert(vec);
                    }
                }
            }
            // T.C n*m * log(n*m) + (n*m*4) 
            return st.size();
        }
};