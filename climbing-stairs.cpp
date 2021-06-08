#include<bits/stdc++.h>
using namespace std;

// for leetcode class based code
// vector<int> memo;
// Solution(): memo(50, -1) {}

//for current code
vector<int> memo(50, -1);

int climbStairs(int n) {
    if (memo[n] >= 0) return memo[n];
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int steps = climbStairs(n - 1) + climbStairs(n - 2);
    memo[n] = steps;
    return steps;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cout<<climbStairs(n);
	
	return 0;
}
