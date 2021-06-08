#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int best = INT_MIN, sum = 0, n = nums.size();
    int maximum = INT_MIN;
    for(int i = 0; i < n; ++i) {
        if (nums[i] >= maximum) {
            maximum = nums[i];
        }
        sum = max(nums[i], sum + nums[i]);
        best = max(sum, best);
    }
    return max(maximum, best);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> nums;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	cout<<maxSubArray(nums);
	
	return 0;
}
