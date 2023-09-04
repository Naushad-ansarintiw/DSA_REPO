#include <iostream>
#include <vector>
using namespace std;

const int R = 4, C = 4;
void printSpiral(int mat[4][4], int R, int C) {
 int top = 0, left = 0, bottom = R - 1, right = C - 1;
 while (top<=bottom && left<=right)
 {
      for (int i = left; i <= right; i++)
       { cout << mat[top][i] << " "; } 
       top++;

       for (int i = top; i <= bottom; i++)
       { cout << mat[i][right] << " "; }
       
       right--;

       if(top<=bottom){
        for (int i = right; i >= left; i--)
         { cout << mat[bottom][i] << " "; }

         bottom--;
       }

      if (left <= right) {
      for (int i = bottom; i >= top; i--)
        cout << mat[i][left] << " ";
      left++;
    }
      
 }
 
}

int main(){

    // Approch
//     In each outer loop traversal print the elements of a square in a clockwise manner.
// Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.
// Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
// Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom
// Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.
// Run a loop until all the squares of loops are printed.
// Time Complexity: O(R x C)

  int arr[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
	           {9, 10, 11, 12},
		   {13, 14, 15, 16}};
  printSpiral(arr, R, C);
return 0;
}