#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int sLen = s.length();
    int tLen = t.length();
    int i = 0, j = 0;
    if (sLen > tLen) return false;
    while(j < tLen and i < sLen) {
        if (s[i] == t[j]) {
            i++;
            j++;
            continue;
        }
        j++;
    }
    if (i == sLen) return true;
    else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s, t;
	cin>>s>>t;
	cout<<isSubsequence(s, t);
	
	return 0;
}
