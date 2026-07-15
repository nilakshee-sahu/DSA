class Solution {
public:
    int countReqDays(vector<int>& weights, int capacity){
        int days = 1;
        int load = 0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += weights[i];
        }

        int low = *max_element(weights.begin(), weights.end());
        int high = sum;
        while(low <= high){
            int mid = low + (high-low)/2;
            int reqDays = countReqDays(weights, mid);
            if(reqDays <= days)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};