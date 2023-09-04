void subArraySum(int a[],int k){
    int curSum = 0,count = 0;
    unordered_map<int,int> mpp;
    for(int i = 0;i<n;i++){
        curSum += a[i];
        if(curSum == k) count++;
        if(mpp.find(curSum - k)){
            count++;
        }
        mpp.push_back(curSum,i);
    }
}