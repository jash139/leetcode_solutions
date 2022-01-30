class Solution {
public:
    int numTrees(int n) {
        vector<int> cache{1};
        
        for (int m = 1; m < n + 1; ++m) {
            int numOfTrees = 0;
            for (int leftTreeSize = 0; leftTreeSize < m; ++leftTreeSize) {
                int rightTreeSize = m - leftTreeSize - 1;
                int numLeftSubtrees = cache[leftTreeSize];
                int numRightSubtrees = cache[rightTreeSize];
                
                numOfTrees += numLeftSubtrees * numRightSubtrees;
            }
            cache.push_back(numOfTrees);
        }
                
        return cache[n];
    }
};
