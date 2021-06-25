#include<bits/stdc++.h>
using namespace std;

// O(n ^ 2) Time | O(n) Space
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int targetSum = 0;
    vector<vector<int>> triplets;
    
    for (int idx = 0; idx < len - 2; ++idx) {
        if ((idx > 0) and (nums[idx - 1] == nums[idx])) continue;
        int leftIdx = idx + 1;
        int rightIdx = len - 1;
        while (leftIdx < rightIdx) {
            int currSum = nums[idx] + nums[leftIdx] + nums[rightIdx];
            if (currSum > targetSum) rightIdx--;
            else if (currSum < targetSum) leftIdx++;
            else {
                triplets.push_back({ nums[idx], nums[leftIdx], nums[rightIdx] });
                // handle duplicate values
                while (leftIdx < rightIdx and nums[leftIdx] == nums[leftIdx + 1]) leftIdx++;
                while (leftIdx < rightIdx and nums[rightIdx] == nums[rightIdx - 1]) rightIdx--;
                leftIdx++;
                rightIdx--;
            }
        }
    }
    
    return triplets;
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
	vector<vector<int>> triplets = threeSum(nums);
	for (int i = 0; i < triplets.size(); ++i) {
		vector<int> triplet = triplets[i];
		for (int j = 0; j < 3; ++j) {
			cout<<triplet[j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
