class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(nums.empty()) return {};

        unordered_map<int, int> mp;
        vector<int> ans;

        for(int num: nums){
            mp[num]++;
        }

        int maxi = 0;
        int key;
        for(int i=1; i<=k; i++){
            for(auto &p: mp){
                if(p.second > maxi){
                    maxi = p.second;
                    key = p.first;
                }  
            }
            ans.push_back(key);
            maxi = 0;
            mp.erase(key);
        }
        return ans;
    }
};