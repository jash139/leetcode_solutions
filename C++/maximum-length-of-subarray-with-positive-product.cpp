class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positiveLength = 0;
        int negativeLength = 0;
        
        int maxLength = 0;
        
        for (int n : nums) {
            if (n == 0) {
                positiveLength = 0;
                negativeLength = 0;
            } else if (n > 0) {
                positiveLength++;
                negativeLength = negativeLength == 0 ? 0 : negativeLength + 1;
            } else {
                positiveLength++;
                negativeLength = negativeLength == 0 ? 0 : negativeLength + 1;
                
                swap(positiveLength, negativeLength);
            }
            
            maxLength = max(maxLength, positiveLength);
        }
        
        return maxLength;
    }
};
