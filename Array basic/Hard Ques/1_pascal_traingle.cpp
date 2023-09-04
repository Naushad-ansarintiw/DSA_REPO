#include <iostream>
#include <vector>
using namespace std;\

int factorial(int n){
    if(n  == 1 || n == 0){
        return 1;
    }
    int sum=n*factorial(n-1);
    return sum;
}


void pascalTriangle(int n){
    for(int i = 0; i<n;i++){
        for (int j = 0; j <= i; j++)
        {
            cout<<(factorial(i)/(factorial(j)*factorial(i-j))) <<" ";
        }
       cout<<endl; 
    }
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);

     for (int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
     }      
    return r;
}

int main(){
     int n;
     cin>>n;
     // First Method (iCj) --> combination of j number in i 
     // Time Complexity = O(n!).
    // space complexity = O(1)

    //  pascalTriangle(n);

    // Second Method
    // Approach: 
    // 1. Create an array of size (i + 1) (For some languages such as C++, you need to create    a   2D array at the start of the program and resize array[i] to (i + 1)).
    // 2. Set the first and last value of array[i] to 1.
    // 3. Run another loop from j = 1 to i – 1 (inclusive) and for each iteration put array[i][j] = array[i – 1][j – 1] + array[i – 1][j].
    // Time Complexity = O(rows * rows).
    // space complexity = O(rows * rows)
    
    vector<vector<int>> a = generate(n);
    for(auto vec: a){
        for(auto it: vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
return 0;
}