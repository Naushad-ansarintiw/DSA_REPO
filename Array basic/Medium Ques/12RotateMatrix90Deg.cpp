#include <bits/stdc++.h>
using namespace std;

// First Method
vector < vector < int >> rotateMethod1(vector < vector < int >> & matrix) {
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[i][j] = matrix[n-1-j][i];
    }
  }
  return rotated;
}

//Second Method
void rotateMethod2(vector < vector < int >> & matrix) {
  int n = matrix.size();
  //transposing the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  //reversing each row of the matrix
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main(){
     
// First Method (Brute Force)

//    Approach: Take another dummy matrix of n*n, and then take the first coloum of the matrix and put it in the first row from buttom element at first element of row of the dummy matrix, take the second coloum of the matrix and put it in the first row from buttom element at second element of row of the matrix and so.
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)

//   vector < vector < int >> arr;
//   arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//   vector < vector < int >> rotated = rotateMethod1(arr);
//   cout << "Rotated Image" << endl;
//   for (int i = 0; i < rotated.size(); i++) {
//     for (int j = 0; j < rotated[0].size(); j++) {
//       cout << rotated[i][j] << " ";
//     }
//     cout << "\n";
//   }

// Second Method (Optimize Approach)

// Step1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)
// Step2: Reverse each row of the matrix.

// Time Complexity: O(N*N) + O(N*N)
// Space Complexity: O(1).

  vector<vector<int>> arr;
  arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   rotateMethod2(arr);
  cout << "Rotated Image" << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }



   
   
return 0;
}