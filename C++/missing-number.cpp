#include<bits/stdc++.h>
using namespace std;

// O(n) Time | O(1) Space
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int reqSum = (n * (n + 1)) / 2;
    int sum = 0;
    for (int idx = 0; idx < n; ++idx) {
        sum += nums[idx];
    }
    return reqSum - sum;
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
	cout<<missingNumber(nums);
	
	return 0;
}
