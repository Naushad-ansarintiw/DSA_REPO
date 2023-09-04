
//O(n) T.C
//O(k) s.C
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){

    deque<long long int> dq;
    vector<long long> ans;

    // process first window of k size

    for(int i=0; i<k; i++){
        if(A[i] < 0) 
            dq.push_back(i);
    }

    // store answer of first k sized window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else {
      ans.push_back(0);  
    }

    // process for remaining window

    for(int i=k; i<N; i++){
        // removal 

        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        // addition
        if(A[i]<0){
            dq.push_back(i);
        }

        // ans store
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else {
      ans.push_back(0);  
    }      
    }
    return ans;
}