class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1, streak = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            if(nums[i]+1 == nums[i+1]){
                streak++;
            }
            else{
                longest = max(longest, streak);
                streak = 1;
            }
        }
        return max(longest, streak);
    }
};