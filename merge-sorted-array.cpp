#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    
    vector<int> ans;
    while(i < m and j < n) {
        if (nums1[i] < nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
        } else if (nums1[i] > nums2[j]) {
            ans.push_back(nums2[j]);
            j++;
        } else {
            ans.push_back(nums1[i]);
            ans.push_back(nums2[j]);
            i++;
            j++;
        }
    }
    if (i < m) {
        for(int k = i; k < m; ++k) {
            ans.push_back(nums1[k]);
        }
    }
    if (j < n) {
        for(int k = j; k < n; ++k) {
            ans.push_back(nums2[k]);
        }
    }
    for(int k = 0; k < m + n; ++k) {
        nums1[k] = ans[k];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m, n;
	cin>>m>>n;
	vector<int> nums1, nums2;
	for(int i = 0; i < m; ++i) {
		int t;
		cin>>t;
		nums1.push_back(t);
	}
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		nums2.push_back(t);
	}
	merge(nums1, m, nums2, n);
	for(int i = 0; i < n + m; ++i) {
		cout<<nums1[i]<<" ";
	}
	return 0;
}
