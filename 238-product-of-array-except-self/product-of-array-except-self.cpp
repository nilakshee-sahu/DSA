class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int countZero = 0;
        long long totalProduct = 1;
        int zeroIndex = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                countZero++;
                zeroIndex = i;
            } else {
                totalProduct *= nums[i];
            }
        }

        if(countZero == 0) {
            for(int i = 0; i < n; i++) {
                ans[i] = totalProduct / nums[i];
            }
        } 
        else if(countZero == 1) {
            ans[zeroIndex] = totalProduct;
        } 
        
        return ans;
    }
};
