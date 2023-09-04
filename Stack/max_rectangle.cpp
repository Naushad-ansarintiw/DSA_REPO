// T.C O(n*m)
// S.C O(m)

class Solution{
    private: 
        vector<int> prevSmallerElement(int* heights, int n){
              vector<int> prev(n);
              stack<int> s;
              s.push(-1);

              for(int i=0;i<n;i++){
                int curr = heights[i];
                while(s.top() != -1 && heights[s.top()] > element){
                    s.pop();
                }
                prev[i] = s.top();
                s.push(i);
              }
              return prev;
        }

        vector<int> nextSmallerElement(int* heights, int n){
              vector<int> next(n);
              stack<int> s;
              s.push(-1);

              for(int i=n-1; i>=0; i--){
                int curr = heights[i];
                while(s.top() != -1 && heights[s.top]>curr){
                    s.pop();
                }
                next[i] = s.top();
                s.push(i);
              }

              return next;
        }

        int largestRectangleArea(int* heights) {
            int n=heights.size();

            vector<int> next(n);
            next = nextSmallerElement(heights,n);

            vector<int> prev(n);
            prev = prevSmallerElement(heigths,n);

            int area = INT_MIN;

            for(int i=0; i<n; i++){
                int l = heights[i];
                if(next[i] == -1){
                    next[i] = n;
                }

                int b = next[i] - prev[i] -1;
                int newArea = l*b;
                area = max(area,newArea);
            }
            return area;
        }

    public: 
        int maxArea(int M[MAX][MAX], int n, int m){

                // compute area for first row
                int area = largestRectangleArea(M[0] , m);

                for(int i = 1; i<n; i++){
                    for(int j=0; j<m; j++){
                        // row updates: by adding previous row's value
                        if(M[i][j] != 0)
                            M[i][j] = M[i-1][j]+m[i][j];
                        else 
                            M[i][j] = 0; 
                    }
                   // entire row is updated now

                   // compute the area
                   area = max(area,largestRectangleArea(M[i] , m));
                }
        }
        return ans;
}