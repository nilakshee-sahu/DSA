class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto& p: mp){
            if(p.second > n/2)
                return p.first;
        }
        return -1;
    }
};