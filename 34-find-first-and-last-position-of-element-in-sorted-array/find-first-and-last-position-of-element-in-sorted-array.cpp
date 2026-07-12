class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};

        int n = nums.size();
        int low = 0, high = n-1;
        int first = -1, last = -1;

        // For finding first occurrence
        while (low <= high) {
            int mid = low + (high - low)/2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; 
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // For finding last occurrence
        low = 0; high = n-1;
        while (low <= high) {
            int mid = low + (high - low)/2;

            if (nums[mid] == target) {
                last = mid;
                low = mid+1;
            }
            else if (nums[mid] < target) {
                last = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
               
        }

        if(first == -1 ) return {-1, -1};
        return {first, last};
    }
};