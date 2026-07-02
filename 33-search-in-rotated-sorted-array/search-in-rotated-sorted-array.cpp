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
    
    int findMinIdx(vector<int>& arr, int n){
        int s = 0;
        int e = n-1;

        while(s<e){
            int mid = s + (e-s)/2;

            if(arr[mid] > arr[e]){
                s = mid+1;
            }
            else {
                e = mid;
            }
        }
        return s;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot =  findMinIdx(nums, n); //minimum number will be the pivot
        
        if(pivot == 0) {
            return binarySearch(nums, target, 0, n-1);
        }
        else if(target >= nums[0] && target <= nums[pivot-1]){
            return binarySearch(nums, target, 0, pivot-1);
        } 
        else{
            return binarySearch(nums, target, pivot, n-1);
        }
    }
};