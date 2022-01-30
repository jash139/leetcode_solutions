class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        maxLength = max(getMaxLengthInDirection(s, true), getMaxLengthInDirection(s, false));
        return maxLength;
    }
    
    int getMaxLengthInDirection(string s, bool isRight) {
        int maxLength = 0;
        int step = 1;
        int start = 0;
        char openingParen = '(';
        
        if (isRight == false) {
            step = -1;
            start = s.size() - 1;
            openingParen = ')';
        }
        
        int i = start;
        int leftParenthesesCount = 0;
        int rightParenthesesCount = 0;
        
        while (i >= 0 and i < s.size()) {
            char paren = s[i];
            if (paren == openingParen) {
                leftParenthesesCount++;
            } else {
                rightParenthesesCount++;
            }
            
            if (leftParenthesesCount == rightParenthesesCount) {
                maxLength = max(maxLength, 2 * leftParenthesesCount);
            } else if (rightParenthesesCount >= leftParenthesesCount) {
                leftParenthesesCount = 0;
                rightParenthesesCount = 0;
            }
            i += step;
        }
        
        return maxLength;
    }
};
