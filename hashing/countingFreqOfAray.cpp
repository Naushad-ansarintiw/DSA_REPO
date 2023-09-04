#include <iostream>
using namespace std;

bool isVisited(bool visited[],int index){
     if(visited[index] == true) return true;
     else return false;
}

int main(){
     int arr1[] = {10,5,10,15,10,5,2,2,9};
     int n = 9;
     int count = 1;
     bool visitedAray[n] = {false};
     for (int i = 0; i < n; i++)
     {
        if(!isVisited(visitedAray,i)){
            visitedAray[i] = true;
        for (int j = 1; j < n; j++)
        {
               if (arr1[i] == arr1[j])
               {
                   count++;
                   visitedAray[j] = true;
               }
         } 
        cout<<arr1[i] << " "<<count<<endl;
        }
        count = 0;
     }
return 0;
}