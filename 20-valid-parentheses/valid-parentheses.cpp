class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        int i=0;
        while(i < n){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()) return false;
                char tp = st.top(); st.pop();
                if(s[i] == ')' && tp != '(') return false;
                if(s[i] == '}' && tp != '{') return false;
                if(s[i] == ']' && tp != '[') return false;
            }
            i++;
        }
        return st.empty();
    }
};