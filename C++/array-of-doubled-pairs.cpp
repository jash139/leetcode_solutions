class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> count;
        
        for (auto num : arr) {
            count[num]++;
        }
        
        for (auto num : arr) {
            if (count[num] == 0)
                continue;
            
            if (num < 0 and num % 2 != 0)
                return false;
            
            int pair = num > 0 ? num * 2 : num / 2;
            if (count[pair] == 0)
                return false;
            
            count[num]--;
            count[pair]--;
        }
        
        return true;
    }
};
