char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int* dp = (int*)calloc(n + 4, sizeof(int));
    
    for (int i = n - 1; i >= 0; i--) {
        int max_diff = INT_MIN;
        int sum = 0;
        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            int diff = sum - dp[i + k + 1];
            if (diff > max_diff) {
                max_diff = diff;
            }
        }
        dp[i] = max_diff;
    }
    
    int result = dp[0];
    free(dp);
    
    if (result > 0) {
        return "Alice";
    } else if (result < 0) {
        return "Bob";
    } else {
        return "Tie";
    }
}