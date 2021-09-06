class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int ans = 0;
        
        int currBit;
        int bitsCount;
        int pos = 0;
        
        // Total 32 bits integer
        for (int j = 0; j < 32; ++j) {
            bitsCount = 0;
            
            // Get sum of j th bit for all numbers
            for (int i = 0; i < nums.size(); ++i) {
                currBit = nums[i] & 1;
                bitsCount += currBit;
                nums[i] >>= 1;
            }
            
            bitsCount %= 3;
            
            // The remaining bit is for the unique element
            ans += bitsCount * pow(2, pos);
            pos++;
        }
        
        return ans;
    }
};
