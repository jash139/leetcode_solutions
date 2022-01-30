class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // drops lowest set bit
            count++;
        }
        return count;
        
        // bitset<32> bits(n);
        // return bits.count();
    }
};
