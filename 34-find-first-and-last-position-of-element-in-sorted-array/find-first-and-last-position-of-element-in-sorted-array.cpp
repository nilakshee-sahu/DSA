class Solution {
public:
    int lowerBound (vector<int>& nums, int n, int target) {
        int low = 0, high = n-1;
        int first = n;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] >= target) {
                first = mid;
                high = mid - 1; 
            }
            else {
                low = mid + 1;
            }
        }
        return first;
    }

    int upperBound (vector<int>& nums, int n, int target) {
        int low = 0, high = n-1;
        int last = n;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] > target) {
                last = mid;
                high = mid - 1; 
            }
            else {
                low = mid + 1;
            }
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int n = nums.size();
        
        int lb = lowerBound(nums, n, target); 
        int up = upperBound(nums, n, target);

        if(lb == n || nums[lb] != target)
            return {-1, -1};

        return {lb, up-1};
    }
};