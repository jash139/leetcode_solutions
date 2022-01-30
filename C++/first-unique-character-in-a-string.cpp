#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    vector<int> count(26, 0);
    int index = -1;
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        count[s[i] - 97]++;
    }
    for(int i = 0; i < n; ++i) {
        if (count[s[i] - 97] == 1) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	cout<<firstUniqChar(s);
	
	return 0;
}
