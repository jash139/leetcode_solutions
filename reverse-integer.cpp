#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int r = 0;
    while(x) {
        int rem = x % 10;
        if (r > INT_MAX / 10 || r == INT_MAX / 10 && rem > 7) return 0;
        if (r < INT_MIN / 10 || r == INT_MIN / 10 && rem < -8) return 0;
        r = r * 10 + rem;
        x /= 10;
    }
    
    return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cout<<reverse(n);
	
	return 0;
}
