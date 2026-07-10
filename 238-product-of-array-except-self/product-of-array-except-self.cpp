class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int countZero = 0;
        long long totalProduct = 1;
        int zeroIndex = -1;

        // Step 1: Count zeros and compute product of non-zero elements
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                countZero++;
                zeroIndex = i;
            } else {
                totalProduct *= nums[i];
            }
        }

        // Step 2: Handle cases
        if(countZero == 0) {
            // No zero → divide total product by nums[i]
            for(int i = 0; i < n; i++) {
                ans[i] = totalProduct / nums[i];
            }
        } 
        else if(countZero == 1) {
            // Exactly one zero → only that index gets product of others
            ans[zeroIndex] = totalProduct;
        } 
        else {
            // More than one zero → all results are zero
            // ans already initialized with zeros
        }

        return ans;
    }
};
