class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Store prefix sum
        vector<int> preSum(n);
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            preSum[i] = sum;
        }

        int count = 0;
        unordered_map<int, int> mp;
        for(int j=0; j<n; j++){
            if(preSum[j] == k) {
                count++;
            }

            int comp = preSum[j] - k;
            if(mp.find(comp) != mp.end()){
                count += mp[comp];
            }
                
            mp[preSum[j]]++;
        }
        return count;
    }
};