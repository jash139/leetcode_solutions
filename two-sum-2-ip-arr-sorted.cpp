#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int start = 0, end = n - 1;
    
    vector<int> ans;
    while(true) {
        if (numbers[start] + numbers[end] == target) {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            break;
        }
        if (numbers[end] > target - numbers[start]) {
            end--;
        }
        if (numbers[start] < target - numbers[end]) {
            start++;
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
	cout<<ans[0]<<" "<<ans[1];
	return 0;
}
