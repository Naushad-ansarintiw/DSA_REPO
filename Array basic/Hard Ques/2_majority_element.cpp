#include <iostream>
using namespace std;


// Method 1
vector < int > majorityElement1(int arr[], int n) {
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == arr[i])
        cnt++;
    }

    if (cnt > (n / 3)) 
      ans.push_back(arr[i]);
  }

  return ans;
}

// Method 2

vector < int > majorityElement(int arr[], int n) {
  unordered_map < int, int > mp;
  vector < int > ans;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }

  return ans;
}


void find(int nums[],int n){
  int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}  

int main(){
  int arr[] = {1,2,2,3,2};
  vector<int> majority;

    // Method 1 (Brute Force)
    //  Approach: Simply count the no. of appearance for each element using nested loops and whenever you find the count of an element greater than N/3 times, that element will be your answer.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

//    majority = majorityElement1(arr, 5);

   // Method 2 (Better Solution)
//    Approach: Traverse the whole array and store the count of every element in a map. After that traverse through the map and whenever you find the count of an element greater than N/3 times, store that element in your answer.

    // majority = majorityElement2(arr,5);

    // Method 3(Extented Boyer Moore,s Voting algorithm)
    
  cout << "The majority element is" << endl;
  set < int > s(majority.begin(), majority.end());
  for (auto it: s) {
    cout << it << " ";
  }
    
return 0;
}