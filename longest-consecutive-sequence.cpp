class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> isPresent;
        for (auto num : nums)
            isPresent[num] = 1;
        
        int maxCount = 0;
        for (auto num : nums) {
            if (isPresent[num] == 0)
                continue;
            
            int curCount = 1;
            int left = num - 1;
            int right = num + 1;
            while (true) {
                if (isPresent.find(right) != isPresent.end()) {
                    isPresent[right] = 0;
                    curCount++;
                    right++;
                } else
                    break;
            }
            while (true) {
                if (isPresent.find(left) != isPresent.end()) {
                    isPresent[left] = 0;
                    curCount++;
                    left--;
                } else
                    break;
            }
            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};
