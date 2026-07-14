class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int days, int m, int k){
        int count = 0;
        int totalBouquets = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days) count++;
            else{
                totalBouquets += (count/k);
                count = 0;
            }
        }
        totalBouquets += (count / k);

        return totalBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }
        return ans;
    }
};