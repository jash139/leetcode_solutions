#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> isPresent;
    int len = nums.size();
    vector<int> ans;
    for(int i = 0; i < len; ++i) {
        if (isPresent.find(target - nums[i]) == isPresent.end()) {
            isPresent[nums[i]] = i;
        } else {
            ans.push_back(isPresent[target - nums[i]]);
            ans.push_back(i);
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
	int target;
	
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}
	cin>>target;
	vector<int> ans = twoSum(nums, target);
	cout<<ans[0]<<" "<<ans[1]<<"\n";
	
	return 0;
}
