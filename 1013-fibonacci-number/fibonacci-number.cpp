class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }

    int helper(int n, vector<int>& dp){
        // Base case
        if(n == 1 || n == 0) return n;

        // Check value in dp
        if (dp[n] != -1) return dp[n];

        // Calculate value
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }
};