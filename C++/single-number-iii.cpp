class Solution {
public:
//     By XORing all the numbers, we get the XOR of the two target numbers because XORing two duplicate numbers always results in 0.
//     The two numbers that appear only once must differ at some bit.
//     Let’s say the at the ith bit, the two desired numbers differ from each other. which means one number has bit i equaling: 0, the other number has bit i equaling 1.
        
//     Thus, all the numbers can be partitioned into two groups according to their bits at location i.
//     The first group consists of all numbers whose bits at i is 0.
//     The second group consists of all numbers whose bits at i is 1.
        
//     If a duplicate number has bit i as 0, then, two copies of it will belong to the first group. Similarly, if a duplicate number has bit i as 1, then, two copies of it will belong to the second group.

//     By XoRing all numbers in the first group, we can get the first number.
//     By XoRing all numbers in the second group, we can get the second number.
    
    
    vector<int> singleNumber(vector<int>& nums) {
        long long int aXORb = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            aXORb ^= nums[i];
        }
        
        // Get rightmost set bit
        long long int rightMostSetBit = aXORb & -aXORb;
        vector<int> result(2, 0);
        
        for (int num : nums) {
            if ((rightMostSetBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        
        return result;
    }
};
