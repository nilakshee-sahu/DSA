class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        int mindiff = INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            if(abs(arr[i]-arr[i+1]) > 0)
                mindiff = min(mindiff, abs(arr[i]-arr[i+1]));
        }
        for(int i=0; i<arr.size()-1; i++){
            vector<int> res;
            if(abs(arr[i]-arr[i+1]) == mindiff){
                res.push_back(arr[i]);
                res.push_back(arr[i+1]);
            }
            if(res.size() != 0) ans.push_back(res);
        }
        return ans;
    }
};