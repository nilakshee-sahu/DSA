class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(nums.empty()) return {};

        unordered_map<int, int> freq;
        vector<int> ans;

        for(int num: nums){
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        for(int i= buckets.size()-1; i>=0 && ans.size()<k; i--){
            for(int num : buckets[i]) {
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};