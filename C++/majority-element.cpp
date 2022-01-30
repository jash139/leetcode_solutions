#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if (count.find(nums[i]) == count.end()) {
            count[nums[i]] = 1;
        } else {
            count[nums[i]]++;
        }
    }
    int ans;
    for(int i = 0; i < n; ++i) {
        if (count[nums[i]] > (n / 2)) {
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
	
	int n;
	cin>>n;
	vector<int> nums;
	
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	cout<<majorityElement(nums);
	return 0;
}
