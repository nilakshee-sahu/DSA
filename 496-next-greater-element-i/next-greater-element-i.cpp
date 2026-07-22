class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nge(n1);
        // stack<int> st;

        for(int i=0; i<n1; i++){
            auto idx = find(nums2.begin(), nums2.end(), nums1[i]);
            int index = distance(nums2.begin(), idx);
            for(int j=index+1; j<n2; j++){
                if(nums2[j]>nums2[index]){
                    nge[i] = nums2[j];
                    break;
                }
                nge[i] = -1;
            }
        }
        for(int i=0; i<n1; i++){
            if(nge[i] == 0) nge[i] = -1;
        }
        return nge;
    }
};