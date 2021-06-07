#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int len = s.length();
    int ans = 0;
    int j = len - 1;
    while(s[j] == ' ' and j != 0) {
        j--;
    }
    for(int i = j; i >= 0; --i) {
        if (s[i] == ' ') {
            break;
        }
        ans++;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	getline(cin, str);
	cout<<lengthOfLastWord(str);
	return 0;
}
