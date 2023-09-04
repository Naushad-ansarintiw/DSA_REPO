// S.C O(n^2)
// T.C O(n^2)


class Solution {
    private:
        void bfs(int row, int col, vector<vector<int> > &vis, vector<vector<int> > &grid){
            vis[row][col] = 1;
            queue<pair<int, int> > q;
            q.push(make_pair(row, col));
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                int n = grid.size();
                int m = grid[0].size();
                q.pop();

                //  traverse the neighbors and mark them if its is a land
                for(int delrow = -1; delrow <= 1;delrow++){
                    for(int delcol = -1; delcol <= 1;delcol++){
                            int nrow = row + delrow;
                            int ncol = col + delcol;
                            if((nrow >= 0 && nrow < n) && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                                vis[nrow][ncol] = 1;
                                q.push(make_pair(nrow, ncol));
                            }
                        }
                    }
                }
            }
        }
    public:
        // Function to find the number of islands
        int numIslands(vector<vector<int>>& grid) {
            int cnt = 0;
            int n = grid.size();
            int m = grid[0].size();
            
            vector<vector<int>> visited(n, vector<int>(m, 0));
            
            for(int row = 0; row < n; ++row){
                for(int col = 0; col < m; ++col){
                   if(!visited[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, visited, grid);
                   } 
            }
        }
        return cnt;
}

};