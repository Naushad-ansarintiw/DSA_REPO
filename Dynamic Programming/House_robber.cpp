// same as maximum_sum_of_non_adjacent_valus
// memorization and tabulation same as this question maximum_sum_of_non_adjacent_valus

// this is spcae optimize code of this question(maximum_sum_of_non_adjacent_valus)

long long int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;

    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i>1) take += prev2;

        int notTake = 0 + prev;

        long long int curi = max(take, notTake);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

long long int houseRobber(vector<int>& valueInHouse){
      vector<int> temp1, temp2;

      int n = valueInHouse.size();
      if(n==1) return valueInHouse[0];
      for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
      }

      return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}
