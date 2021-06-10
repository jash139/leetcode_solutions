#include<bits/stdc++.h>
using namespace std;

//Approach 1 : Without counting
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if (nums[mid] == 0) {
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(&nums[high], &nums[mid]);
            high--;
        }
    }
}

////Approach 2 : With counting
//void sortColors(vector<int>& nums) {
//    int n = nums.size();
//    int count[3] = {0};
//    for(int i = 0; i < n; ++i) {
//        count[nums[i]]++;
//    }
//    int j = 0;
//    for(int i = 0; i < n;) {
//        int c = count[j];
//        while(c) {
//            nums[i] = j;
//            i++;
//            c--;
//        }
//        j++;
//    }
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
	
	sortColors(nums);
	for(int i = 0; i < n; ++i) {
		cout<<nums[i]<<" ";
	}
	
	return 0;
}
