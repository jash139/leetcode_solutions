#include<bits/stdc++.h>
using namespace std;

vector<int> memo(1001, -1);

int minCost(int n, vector<int>& cost) {
    if (memo[n] > -1) return memo[n];
    if (n <= 1) return 0;
    
    int mCost = min(cost[n - 1] + minCost(n - 1, cost), cost[n - 2] + minCost(n - 2, cost));
    memo[n] = mCost;
    return mCost;
}

int minCostClimbingStairs(vector<int>& cost) {
    return minCost(cost.size(), cost);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> cost;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		cost.push_back(t);
	}
	cout<<minCostClimbingStairs(cost);
	
	return 0;
}
