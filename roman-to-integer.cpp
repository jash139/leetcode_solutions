class Solution {
public:
    int getIntValue(char ch) {
        switch (ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return -1;
    }
    
    int romanToInt(string s) {
        int value = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() and getIntValue(s[i]) < getIntValue(s[i + 1]))
                value -= getIntValue(s[i]);
            else
                value += getIntValue(s[i]);
        }
        
        return value;
    }
};
