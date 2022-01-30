#include<bits/stdc++.h>
using namespace std;

bool matchBracket(char cur, char top) {
    switch(cur) {
        case ')':
            if (top == '(') return true;
            else return false;
        case '}':
            if (top == '{') return true;
            else return false;
        case ']':
            if (top == '[') return true;
            else return false;
        default:
            return false;
    }
}
bool isValid(string s) {
    stack<char> stack;
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        char cur = s[i];
        if (cur == '(' or cur == '{' or cur == '[') {
            stack.push(cur);
        } else {
            if (!stack.empty()) {
                char top = stack.top();
                bool res = matchBracket(cur, top);
                if (res) {
                    stack.pop();
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if (stack.empty()) return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin>>s;
	
	if (isValid(s)) {
		cout<<"Valid";
	} else {
		cout<<"Invalid";
	}
	
	return 0;
}
