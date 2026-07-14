class Solution {
public:
    int maxi(vector<int>& piles, int n){
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, piles[i]);
        }
        return ans;
    }
    long long calTotalHours(vector<int> piles, int k){
        int n = piles.size();

        long long totalhrs = 0;
        for(int i=0; i<n; i++){
            totalhrs += (piles[i] + k - 1) / k;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = maxi(piles, n);

        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalhrs = calTotalHours(piles, mid);

            if(totalhrs <= (long long)h)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};