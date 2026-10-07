class Solution {
public:
    // Using tabulation
    int tribonacci(int n) {
        // Base case
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;

        for(int i=3; i<=n; i++){
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }    
        return prev1;  
    }
};