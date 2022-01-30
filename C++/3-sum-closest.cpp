#include<bits/stdc++.h>
using namespace std;

// O(n ^ 2) Time | O(1) Space
// n : length of input nums array
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int tripletSum = 0;
    int closestDiff = INT_MAX;
    
    for (int idx = 0; idx < len - 2; ++idx) {
        int leftIdx = idx + 1;
        int rightIdx = len - 1;
        
        while (leftIdx < rightIdx) {
            int currSum = nums[idx] + nums[leftIdx] + nums[rightIdx];
            int currDiff = abs(target - currSum);
            
            if (currDiff < closestDiff) {
                tripletSum = currSum;
                closestDiff = currDiff;
            }
            
            if (currSum <= target) leftIdx++;
            else rightIdx--;
        }
        
    }
    return tripletSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> nums;
	for (int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	int target;
	cin>>target;
	cout<<threeSumClosest(nums, target);
	
	return 0;
}
