#include<bits/stdc++.h>
using namespace std;

// Approach: Floyd's Tortoise and hare algorithm
int findDuplicate(vector<int>& nums) {
    // Find intersection point
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    
    // Find entrance to cycle
    tortoise = nums[0];
    while(tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}

//// Approach: Keep count of elements
//// when > 1 break and return
//int findDuplicate(vector<int>& nums) {
//    int n = nums.size();
//    unordered_map<int, int> count;
//    int res = -1;
//    for(int i = 0; i < n; ++i) {
//        if (count.find(nums[i]) == count.end()) {
//            count[nums[i]] = 1;
//        } else {
//            res = nums[i];
//            break;
//        }
//    }
//    return res;
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
	cout<<findDuplicate(nums);
	
	return 0;
}
