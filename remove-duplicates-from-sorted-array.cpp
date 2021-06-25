#include<bits/stdc++.h>
using namespace std;

// O(n) Time | O(1) Space
// n : length of input nums array
int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    int i = 0;
    for (int j = 1; j < len; ++j) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
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
	int k = removeDuplicates(nums);
	for (int i = 0; i < k; ++i) {
		cout<<nums[i]<<" ";
	}
	
	return 0;
}
