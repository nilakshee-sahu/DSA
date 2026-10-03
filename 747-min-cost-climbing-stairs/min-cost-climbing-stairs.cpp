class Solution {
public:
    // SPACE OPTIMIZATION Approach
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1) return cost[n];
        
        int prev1 = cost[1];
        int prev2 = cost[0];
        int ans;

        for(int i=2; i<n; i++){
            ans = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = ans;
        }
        return min(prev1, prev2);
    }
};