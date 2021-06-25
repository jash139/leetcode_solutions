#include<bits/stdc++.h>
using namespace std;

// O(n) Time | O(n) Space
// n : length of input nums array
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_map<int, int> isPresent;
    for (int idx = 0; idx < len; idx++) {
        if (isPresent.find(nums[idx]) != isPresent.end() and idx - isPresent[nums[idx]] <= k) {
            return true;
        }
        isPresent[nums[idx]] = idx;
    }
    return false;
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
	int k;
	cin>>k;
	cout<<containsNearbyDuplicate(nums, k);
	
	return 0;
}
