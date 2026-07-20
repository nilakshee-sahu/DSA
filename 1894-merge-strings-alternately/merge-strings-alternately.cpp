class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.length();
        int m = word2.length();
        if(n == m){
            for(int i=0; i<n; i++){
                ans.push_back(word1[i]);
                ans.push_back(word2[i]);
            }
        }
        else if(n < m){
            int i = 0;
            while(i < n){
                ans.push_back(word1[i]);
                ans.push_back(word2[i]);
                i++;
            }
            while(i < m){
                ans.push_back(word2[i]);
                i++;
            }
        }
        else{
            int i = 0;
            while(i < m){
                ans.push_back(word1[i]);
                ans.push_back(word2[i]);
                i++;
            }
            while(i < n){
                ans.push_back(word1[i]);
                i++;
            }
        }
        return ans;
    }
};