#include <bits/stdc++.h>
using namespace std;
int main()
{
   //   int arr[] = {2,2,1,1,1,2,2};
   //   int n = 10;
   // First Method
   // Brute force
   //  Start from the first element of the array and count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element as the answer. If not, proceed with the next element in the array and repeat the process.
   // T.C = O(N2)
   // S.C = O(1)

   // Second Method
   // using map
   //  int maxi = 0;
   //  unordered_map<int,int> mpp;
   //  for(int i = 0;i<n;i++){
   //    int x;
   //    cin>>x;
   //     mpp[x]++;
   //     if(mpp[x]>mpp[maxi]){
   //      maxi =x;
   //     }
   //  }
   // if(mpp[maxi] > floor(n/2)) cout<<maxi<<endl;
   // T.C = O(N)
   // S.C = O(N)

   // Third Method
   // Moore's Voting ALgorithm
   int arr[] = {7,7,5,7,5,1};
   int n = 6;
   int count = 0;
   int max_index = 0;
   for (int i = 0; i < n; i++)
   {
      if (arr[max_index] == arr[i])
         count++;
      else
         count--;
      if (count == 0)
      {
          max_index = i;
         count = 1;
      }
   }
   cout << arr[max_index] << endl;
   return 0;
}