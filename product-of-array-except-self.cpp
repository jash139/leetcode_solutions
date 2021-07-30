#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // O(n) Time | O(n) Space
    // n : length of nums
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> leftProduct(len, 1);
        vector<int> rightProduct(len, 1);
        vector<int> answer(len, 1);
        
        int runningLeftProduct = 1;
        for (int idx = 0; idx < len; ++idx) {
            leftProduct[idx] = runningLeftProduct;
            runningLeftProduct *= nums[idx];
        }
        int runningRightProduct = 1;
        for (int idx = len - 1; idx >= 0; --idx) {
            rightProduct[idx] = runningRightProduct;
            runningRightProduct *= nums[idx];
        }
        
        for (int idx = 0; idx < len; ++idx)
            answer[idx] = leftProduct[idx] * rightProduct[idx];
        
        return answer;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// Add driver code
	
	return 0;
}
