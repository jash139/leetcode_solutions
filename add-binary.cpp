class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int curSum = 0;
        
        while (i >= 0 or j >= 0 or curSum == 1) {
            curSum += (i >= 0 ? a[i] - '0' : 0);
            curSum += (j >= 0 ? b[j] - '0' : 0);
            
            sum = to_string(curSum % 2) + sum;
            
            curSum /= 2;
            i--;
            j--;
        }
        
        return sum;
    }
};
