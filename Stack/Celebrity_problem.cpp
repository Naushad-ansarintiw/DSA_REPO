// T.C O(n)
// S.C O(n)

class Solution {

    private: 
        bool knows(vector<vector<int>& M,int a, int b, int n){
            if(M[a][b] == 1){
                return true;
            }
            else {
                return false;
            }
        }
    public:
        // Function to find if there is a celebrity in the party or not

        int celebrity(vector<vector<int>& M, int n){
            stack<int> s;
            // push all element in stack
            for(int i = 0 ;i<n ; i++){
                    s.push(i);
            }

            while(s.size() > 1){
                int a = s.top();
                s.pop();

                int b = s.top();
                s.pop();

                if(knows(M,a,b,n)){
                    s.push(b);
                }
                else{
                    s.push(a);
                }
            }

            int candidate = s.top();
            // Step3: single element in stack is potential celeberity
            // so verify it

            bool rowCheck = false;
            int zeroCount = 0;

            for(int i=0; i<n; i++){
                if(M[candidate][i] == 0){   
                    zeroCount++;
                }
            }
            // all zeroes
            if(zeroCount == n){
                rowCheck = true;
            }

            // coloumn check
            bool colCheck = false;
            int oneCount = 0;

            for(int i=0; i<n; i++){
                if(M[i][candidate] == 1){
                    oneCount++;
                }
            }

            if(oneCount == n-1){
                colCheck++;
            }

            if(rowCheck == true && colCheck == true){
                return candidate;
            }
            else {
                return -1;
            }

        }
}