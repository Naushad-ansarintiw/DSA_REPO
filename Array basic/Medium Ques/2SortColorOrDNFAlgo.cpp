// Dutch National Flag Algorithm

#include <iostream>
using namespace std;

    void sortColors(int *nums,int n) {
        int lo = 0; 
        int hi =n - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
         
    }
int main(){
     int arr[] = {1,0,2,1,2,2};
     int n = 6;
     sortColors(arr,n);
     for(auto it: arr){
        cout<<it<<" ";
     }
return 0;
}