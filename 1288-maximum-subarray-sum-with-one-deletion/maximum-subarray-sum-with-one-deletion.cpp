class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int prevWithDel = 0;
        int prevNotDel = arr[0];
        int maxi = arr[0];

        for(int i=1; i<n; i++){
            prevWithDel = max(prevNotDel, prevWithDel+arr[i]);
            prevNotDel = max(prevNotDel+arr[i], arr[i]);
            maxi = max(prevWithDel, max(prevNotDel, maxi));
        }
        return maxi;
    }
};