#include<bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    int total = 0;
    for(int i = 1; i < n; ++i) {
        total += min(timeSeries[i] - timeSeries[i - 1], duration);
    }
    return total + duration;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, duration;
	cin>>n>>duration;
	vector<int> timeSeries;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		timeSeries.push_back(t);
	}
	cout<<findPoisonedDuration(timeSeries, duration);
	return 0;
}
