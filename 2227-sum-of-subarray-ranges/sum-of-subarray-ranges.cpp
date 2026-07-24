class Solution {
public:
    vector<int> findNSE(vector<int>& arr, int n){
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr, int n){
        vector<int> psee(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findPSEE(arr, n);

        long long total = 0;
        for(int i=0; i<n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total += right * left * 1LL * arr[i];
        }
        return total;
    }

    vector<int> findNGE(vector<int>& arr, int n){
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGEE(vector<int>& arr, int n){
        vector<int> pgee(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = findNGE(arr, n);
        vector<int> pgee = findPGEE(arr, n);

        long long total = 0;
        for(int i=0; i<n; i++){
            long long left = i - pgee[i];
            long long right = nge[i] - i;

            total += right * left * 1LL * arr[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long largestSum = sumSubarrayMaxs(nums);
        long long smallestSum = sumSubarrayMins(nums);

        return largestSum - smallestSum;
    }
};