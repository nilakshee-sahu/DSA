class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = st.top(); st.pop();
                int nse = i, pse = st.empty()?-1:st.top();
                maxArea = max(heights[el]*(nse-pse-1), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = st.top(); st.pop();
            int nse = n, pse = st.empty()?-1:st.top();
            maxArea = max(heights[el]*(nse-pse-1), maxArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights (n,0);
        int maxArea = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1')
                    heights[j] += 1;
                else 
                    heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};