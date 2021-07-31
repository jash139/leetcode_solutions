class Solution {
public:
    // idx & (idx - 1) drops the lowest set bit by 1
    // Example:
    // idx = 14, binary representation = 1110
    // binary representation for idx - 1 = 1101
    // idx & (idx - 1) = 1100
    // the number of "1" in its binary representation decreases by one
    // so countBits[idx] = countBits[idx & (idx - 1)] + 1
    
    // When you remove the lowest set bit (or the rightmost non-zero bit),
    // you will arrive at a smaller number than the current number: 14 ==> 12.
    // Since your computed series already includes all the counts for n = 0,1,2,...,12,13,
    // you will most certainly already have the count for the number 12.
    // So the only difference in count between 14, and 12 is 1 bit,
    // so you add 1 to the count for 12 and get the correct count for 14.
    
    // O(n) Time | O(n) Space
    vector<int> countBits(int num) {
        vector<int> bitsCount(num + 1, 0);
        
        for (int idx = 1; idx <= num; ++idx)
            bitsCount[idx] = bitsCount[idx & (idx - 1)] + 1;
        
        return bitsCount;
    }
    
    // Solution 2
    // vector<int> countBits(int num) {
    //     vector<int> bitsCount(num + 1, 0);
    //     int offset = 1;
    //     for (int idx = 1; idx <= num; ++idx){
    //         if (offset * 2 == idx){
    //             offset *= 2;
    //         }
    //         bitsCount[idx] = bitsCount[idx - offset] + 1;
    //     }
    //     return bitsCount;
    // }
};


