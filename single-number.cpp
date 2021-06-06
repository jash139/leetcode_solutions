#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> numIsPresent;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
        if (numIsPresent.find(nums[i]) == numIsPresent.end()) {
            numIsPresent[nums[i]] = 1;
        } else {
            numIsPresent[nums[i]] = 2;
        }
    }
    int ans = 0;
    for(int i = 0; i < len; ++i) {
        if (numIsPresent[nums[i]] == 1) {
            ans = nums[i];
            break;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<int>nums;
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	cout<<singleNumber(nums);
	
	return 0;
}
