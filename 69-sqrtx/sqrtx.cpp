class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;

        int ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long product = mid*mid;

            if(product <= x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};