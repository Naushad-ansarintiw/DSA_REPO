// Approch 1: find the all possible subarray sum store it into a vector than sort it and find out the kth largest sum 

// T.C O(n^2logn)
// S.C O(n^2)

int getKthLargest(vector<int> &arr, int k){
    vector<int> sumStore;
    int n = arr.size();

    for(int i=0; i<n; i++){
        int sum = 0;

        for(int j=i; j<n; j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size()-k];
}


// Approch 2: using min-heap concept same as Kth smallest element

// T.C O(n^2logn)
// S.C O(k)

int getKthLargest(vector<int> &arr, int k){

    priority_queue<int, vector<int>, greater<int> > mini;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else {
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
        
    }
    return mini.top();
    
}