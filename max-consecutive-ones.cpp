#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int maxCons = INT_MIN, cons = 0;
    for(int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            maxCons = max(maxCons, cons);
            cons = 0;
        } else {
            cons++;
        }
    }
    maxCons = max(maxCons, cons);
    return maxCons;
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
	cout<<findMaxConsecutiveOnes(nums);
	
	return 0;
}
