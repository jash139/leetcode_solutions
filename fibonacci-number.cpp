#include<bits/stdc++.h>
using namespace std;

vector<int> memo(31, -1);
int fib(int n) {
    if (memo[n] > -1) return memo[n];
    if (n <= 1) return n;
    
    return fib(n - 1) + fib(n - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cout<<fib(n);
	
	return 0;
}
