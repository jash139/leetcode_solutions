#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;
bool isHappy(int n) {
    if (n == 1) return true;
    if (!(memo.find(n) == memo.end())) return false;
    
    int sum = 0;
    int num = n;
    while(n) {
        int r = n % 10;
        sum += r * r;
        n /= 10;
    }
    memo[num] = sum;
    return isHappy(sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	cout<<isHappy(n);
	
	return 0;
}
