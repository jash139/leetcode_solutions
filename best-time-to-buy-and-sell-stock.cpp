#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, profit = 0, n = prices.size();
    for(int i = 0; i < n; ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            profit = max(profit, prices[i] - minPrice);
        }
    }
    
    return profit;   
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> prices;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		prices.push_back(t);
	}
	cout<<maxProfit(prices);
	
	return 0;
}
