int climbStairs(int n) {
    if(n<3){
        return n;
    }
    int prev=n-1;
    int prev1=prev-1;
    return prev+prev1;
}