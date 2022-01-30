#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int newSize = n;
    for(int i = 0; i < n; ++i) {
        if (nums[i] == val) {
            nums[i] = -1;
            newSize--;
        }
    }
    sort(nums.begin(), nums.end(), greater<int>());
    return newSize;
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
	int val;
	cin>>val;
	int newSize = removeElement(nums, val);
	for(int i = 0; i < newSize; ++i) {
		cout<<nums[i]<<" ";
	}
	return 0;
}
