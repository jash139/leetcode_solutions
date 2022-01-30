class Solution {
public:
    // O(n) Time | O(1) Space
    // n : number of elements in input array
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        
        int count = 1;
        int currIdx = 1;
        for(int i = 1; i < nums.size(); ++i){
            if (nums[i - 1] == nums[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[currIdx] = nums[i];
                currIdx++;
            }
        }
        return currIdx;
    }
};
