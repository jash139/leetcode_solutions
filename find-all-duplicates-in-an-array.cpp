#include<bits/stdc++.h>
using namespace std;

// Approach 1: iterate through the array, since the numbers
// are in range (1, n) make the postion negative.
// If position turns positive it implies that it appeared twice.
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
        if (nums[abs(nums[i]) - 1] > 0) {
            res.push_back(abs(nums[i]));
        }
    }
    return res;
}

//// Approach 2: counting
//vector<int> findDuplicates(vector<int>& nums) {
//    int n = nums.size();
//    unordered_map<int, int> count;
//    vector<int> ans;
//    for(int i = 0; i < n; ++i) {
//        if (count.find(nums[i]) == count.end()) {
//            count[nums[i]] = 1;
//        } else {
//            count[nums[i]]++;
//            ans.push_back(nums[i]);
//        }
//    }
//    return ans;
//}

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
	
	vector<int> ans = findDuplicates(nums);
	for(int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
