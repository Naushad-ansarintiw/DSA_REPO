

int countDistinctwayToClimbStair(long long n){
    if(n==0 || n==1) return 1;
    int left = countDistinctwayToClimbStair(n-1);
    int right = countDistinctwayToClimbStair(n-2);
    return left + right;
}