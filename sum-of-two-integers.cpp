class Solution {
public:
    int add(int x, int y) {
        while (y != 0) {
            unsigned carry = x & y;
            x = x ^ y;
            y = carry << 1;
        }
        return x;
    }

    int getSum(int a, int b) {
        return add(a, b);
    }
};
