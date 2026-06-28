class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> storeCount;
        //storing the count of each el of array
        int size = arr.size();
        for(int i=0; i<size; i++){
            storeCount[arr[i]]++;
        }

        //push the values to an array
        vector<int> value;
        for(auto &p : storeCount){
            value.push_back(p.second);
        }

        //sort the array
        int n = value.size();
        sort(value.begin(), value.end());

        //check for duplicate
        for (int i=0; i<n-1; i++){
            if(value[i] == value[i+1]){
                return false;
            }
        }
        return true;
    }
};