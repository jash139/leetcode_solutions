#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    while(start < end) {
        char startChar = s[start], endChar = s[end];
        if (iswalnum(startChar) && iswalnum(endChar)) {
            if (startChar == endChar) {
                start++;
                end--;
                continue;
            } else {
                return false;
            }
        } else {
            if (!iswalnum(startChar)) {
                start++;
            }
            if (!iswalnum(endChar)) {
                end--;
            }
        }
    }
    
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	cin>>str;
	if (isPalindrome(str)) {
		cout<<"true";
	} else {
		cout<<"false";
	}
	return 0;
}
