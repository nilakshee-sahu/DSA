class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = s + (e-s)/2;

            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mini = INT_MAX;
        int pivot = 0   ;
        for(int i=0; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                pivot = i;
            }
        }
        if(pivot == 0) {
            return binarySearch(nums, target, 0, n-1);
        }
        if(target >= nums[0] && target <= nums[pivot-1]){
            return binarySearch(nums, target, 0, pivot-1);
        } 
        else{
            return binarySearch(nums, target, pivot, n-1);
        }
    }
};