class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;

        // For +ve and -ve number
        if(i<n && (s[i] == '+' || s[i] == '-')) i++;

        bool digit = false;

        // Digit before or after decimal point
        while(i<n && isdigit(s[i])){
            digit = true;
            i++;
        }

        // Decimal part
        if(i<n && s[i] =='.'){
            i++;
            while(i<n && isdigit(s[i])){
                digit = true;
                i++;
            } 
        }

        // There must be atleast one digit
        if(!digit) return false;

        // Scientific Notation
        if(i<n && (s[i] == 'e' || s[i] == 'E')){
            i++;
            // Sign after e/E
            if(i<n && (s[i] == '+' || s[i] == '-')) i++;

            bool exponentDigit = false;

            while(i<n && isdigit(s[i])){
                exponentDigit = true;
                i++;
            } 

            if(!exponentDigit) return false;
        }
        // If we have traverse the entire string then it is numeric
        return i == n;
    }
};