class Solution {
public:
    int myAtoi(string s) {
        long long int integerValue = 0;
        
        int idx = 0;
        int sign = 1;
        
        while (idx < s.size() and s[idx] == ' ') {
            idx++;
        }
        
        if (idx < s.size() and (s[idx] == '-' or s[idx] == '+')) {
            if (s[idx] == '-')
                sign = -1; 
            idx++;
        }
        
        while (idx < s.size() and isdigit(s[idx])) {
            integerValue = integerValue * 10 + (int)s[idx] - 48;
            if (integerValue * sign <= INT_MIN)
                return INT_MIN;
            if (integerValue * sign >= INT_MAX)
                return INT_MAX;
            idx++;
        }
        
        return (int)integerValue * sign;
    }
};
