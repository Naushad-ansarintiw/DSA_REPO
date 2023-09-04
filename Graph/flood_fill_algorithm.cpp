class Solution {
    private:
        void dfs(int row, int col, vector<vector<int> > &ans, vector<vector<int> > &image, int newColor, int delRow[], int delCol[], int intColor){
            ans[row][col] = newColor;
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == intColor, ans[nrow][ncol] != newColor){
                    dfs(nrow, ncol, ans, image, newColor, delRow, delCol, intColor);
                }
            }
        }

    public:
        vector<vector<int> > floodfill(vector<vector<int> > & image, int sr, int sc, int newColor){
            int intColor = image[sr][sc];
            vector<vector<int> > ans = image;
            int delRow = {-1, 0, +1, 0};
            int delCol = {0, +1, 0, -1};
            dfs(sr, sc, ans, image, newColor, delRow, delCol, intColor);
        }
};