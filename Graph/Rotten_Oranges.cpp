class Solution {
    public:
        int orangesRotting(vector<int>>& grid){
            // Code here
            int n = grid.size();
            int m = grid[0].size();
            // {{r,c},t} // data structure look like this way
            queue<pair <pair<int, int>, int>> q;
            int cntFresh = 0;
            vector<vector<int> > vec;

            for(int i = 0; i<n ; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 2){
                        q.push({{i,j},0});
                        vec[i][j] = 2;
                    }
                    else {
                        vec[i][j] = 0;
                    }  
                    
                    if(grid[i][j] == 1) cntFresh++;
                }
            }

            int tm = 0;
            int cnt = 0;
            int delrow = {-1, 0, +1, 0};
            int delcol = {0, +1, 0, -1};
            
            while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();

                tm = max(tm, t);
                for(int i=0; i<4; i++){
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vec[i][j] != 2){
                        q.push({{nr,nc}, t+1});
                        vec[nr][nc] = 2;
                        cnt++;
                    }
                }
            }
            if(cnt != cntFresh) return -1;

            return tm;
        }
};