#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> count;
    for(int i = 0; i < n; ++i) {
        if (count.find(nums[i]) == count.end()) {
            count[nums[i]] = 1;
        } else {
            return true;
        }
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
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	cout<<containsDuplicate(nums);
	return 0;
}
