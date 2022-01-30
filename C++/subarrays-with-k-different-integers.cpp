class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> mp(nums.size() + 1);

        int goodSubarraysCount = 0;
        
        int j = 0;
        int prefix = 0;
        int count = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            if (mp[nums[i]]++ == 0)
                count++;

            if (count > k) {
                mp[nums[j++]]--;
                count--;
                prefix = 0;
            }
            while (mp[nums[j]] > 1) {
                prefix++;
                mp[nums[j++]]--;
            }
            if (count == k)
                goodSubarraysCount += prefix + 1;
        }

        return goodSubarraysCount;
    }
};
