class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.length() + 1, 0);
        
        ways[0] = 1;
        ways[1] = s[0] == '0' ? 0 : 1;
        
        for (int i = 2; i <= s.length(); ++i) {
            int digitOne = (int)s[i - 1] - 48;
            int digitTwo = ((int)s[i - 2] - 48) * 10 + digitOne;
            
            if (digitOne >= 1)
                ways[i] += ways[i - 1];
            if (digitTwo >= 10 and digitTwo <= 26)
                ways[i] += ways[i - 2];
        }
        
        return ways[s.length()];
    }
};
