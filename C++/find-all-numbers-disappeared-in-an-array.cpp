#include<bits/stdc++.h>
using namespace std;

//// Approach 1
//vector<int> findDisappearedNumbers(vector<int>& nums) {
//    int n = nums.size();
//    vector<int> count(n, 0), ans;
//    for(int i = 0; i < n; ++i) {
//        count[nums[i]]++;
//    }
//    for(int i = 1; i <= n; ++i) {
//        if (count[i] == 0) {
//            ans.push_back(i);
//        }
//    }
//    return ans;
//}

// Approach 2 with no extra space and O(n) time
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if (nums[abs(nums[i]) - 1] > 0) {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    for(int i = 0; i < n; ++i) {
        if (nums[i] >= 0) {
            ans.push_back(i + 1);
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
	vector<int> ans = findDisappearedNumbers(nums);
	int m = ans.size();
	for(int i = 0; i < m; ++i) {
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
