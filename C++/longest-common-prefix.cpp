#include<bits/stdc++.h>
using namespace std;

string findPrefix(string a, string b) {
    string prefix = "";
    int i = 0, j = 0;
    int aLen = a.length(), bLen = b.length();
    while(i < aLen and j < bLen) {
        if (a[i] == b[j]) {
            prefix += a[i];
            i++;
            j++;
        } else {
            break;
        }
    }
    return prefix;
}
string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    int n = strs.size();
    for(int i = 0; i < n - 1; ++i) {
        string cur = strs[i];
        string next = strs[i + 1];
        string tem = findPrefix(cur, next);
        prefix = prefix.length() > tem.length() ? tem : prefix;
    }
    return prefix;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<string> strs;
	for(int i = 0; i < n; ++i) {
		string t;
		cin>>t;
		strs.push_back(t);
	}
	cout<<longestCommonPrefix(strs);
	
	return 0;
}
