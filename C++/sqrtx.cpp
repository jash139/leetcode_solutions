#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    long long int i = 0;
    while(i <= x) {
        if (i * i == x) {
            return i;
        } else if (i * i > x) {
            return i - 1;
        }
        i++;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long int x;
	cin>>x;
	cout<<mySqrt(x);
	
	return 0;
}
