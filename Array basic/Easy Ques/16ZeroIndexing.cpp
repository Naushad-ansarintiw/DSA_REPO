#include <iostream>
#include <vector>
using namespace std;

//First Method

// int rowWithMax1s(vector<vector<bool>> &arr, int n, int m)
// {
// 	int maxiRow1 = -1, count = 0, t = 1, maxi = 0,second=0;
//     for (int i = 0; i <= n * m; i++)
//     {
//         if (i >= 4 * t)
//         {
//             if (maxi < count)
//             {
//                 maxi = count;
//                 maxiRow1 = t-1;
                
//             }
//             count = 0;
//             second = 0;
//             t++;
//             if(i == n*m){
//                 return maxiRow1;
//             }
//         }
//         if (arr[t-1][second] == true) {count++;}
//         second++;
//     }
//     return -1;
// 	}

// Second Method
int rowWithMax1s(vector<vector<bool>> &arr, int n, int m){
    int count = 0,maxi = 0,maxRow=-1;
    for (int i = 0; i < n; i++)
    {
        count = 0;    
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == true) count++;
        }
         if(maxi<count) {maxi = count; maxRow = i; }
    }
    if(maxRow>-1) return maxRow;
    else return -1;
    
}

int main()
{
     vector<vector<bool>> arr = {{false,true,true,true},
                      {false,false,true,true},
                      {false,true,true,true},
                      {false,false,false,false},
                      {true,true,true,true}};
   int s = rowWithMax1s(arr,5,4);
   if(s==-1){
    cout<<"NO"<<endl;
   }
   cout<<s<<endl;

    return 0;
}