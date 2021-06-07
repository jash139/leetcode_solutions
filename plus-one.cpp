#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();
    if (digits[len - 1] < 9) {
        digits[len - 1]++;
        return digits;
    }
    int i = len - 1;
    while(digits[i] == 9 and i > 0) {
        digits[i] = 0;
        i--;
    }
    if (i == 0 and digits[i] == 9) {
        digits[i] = 0;
        digits.insert(digits.begin(), 1);
    } else {
        digits[i]++;
    }
    return digits;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> digits;
	for(int i = 0; i < n; ++i) {
		int t;
		cin>>t;
		digits.push_back(t);
	}
	vector<int>ans = plusOne(digits);
	int len = ans.size();
	for(int i = 0; i < len; ++i) {
		cout<<ans[i];
	}
	return 0;
}
