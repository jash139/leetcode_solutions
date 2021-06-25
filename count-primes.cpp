#include<bits/stdc++.h>
using namespace std;

// O(nloglog(n)) Time | O(n) Space
int countPrimes(int n) {
    vector<bool> primes(n, true);
    for (int num = 2; num * num < n; ++num) {
        if (!primes[num]) continue;
        for (int j = num * num;  j < n; j += num) {
            primes[j] = false;
        }
    }
    int primeCount = 0;
    for (int idx = 2; idx < n; ++idx) {
        if (primes[idx]) {
            primeCount++;
        }
    }
    return primeCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cout<<countPrimes(n);
	
	return 0;
}
