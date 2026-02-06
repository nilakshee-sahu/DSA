class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> count;
        int maxFreq = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            count[arr[i]]++;
            maxFreq = max(maxFreq, count[arr[i]]);
        }

        for (auto &p : count) {
            if (p.second == maxFreq) {
                ans += p.second;
            }
        }
        
        return ans;
    }
};