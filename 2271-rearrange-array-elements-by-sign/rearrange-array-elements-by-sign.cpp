class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> ptv;
        vector<int> ntv;

        for(int i=0; i<n; i++){
            if(nums[i] >= 0) ptv.push_back(nums[i]);
            else ntv.push_back(nums[i]);
        }

        int ptvIdx = 0;
        int ntvIdx = 0;
        vector<int> result(n);
        for(int i=0; i<n; i++){
            if(i%2 == 0) result[i] = ptv[ptvIdx++];
            else result[i] = ntv[ntvIdx++];
        }
        return result;
    }
};