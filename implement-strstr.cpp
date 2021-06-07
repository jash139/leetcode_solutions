#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int index = -1;
    int n = haystack.length();
    int m = needle.length();
    if (m > n) {
        return index;
    }
    if (m == 0) {
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        if (haystack[i] == needle[0]) {
            int j;
            for(j = 0; j < m; ++j) {
                if (haystack[i + j] == needle[j]) {
                    continue;
                } else {
                    break;
                }
            }
            if (j == m) {
                index = i;
                break;
            }
        }
    }
    return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string haystack, needle;
	getline(cin, haystack);
	getline(cin, needle);
	cout<<strStr(haystack, needle);
	
	return 0;
}
