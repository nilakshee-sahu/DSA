class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<int> res;
        for(auto &p: mp){
            if(p.second > n/3)
                res.push_back(p.first);
        }
        return res;
    }
};