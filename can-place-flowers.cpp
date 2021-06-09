#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size();
    if (n == 0) return true;
    for(int i = 0; i < len; ++i) {
        if (flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == len - 1 or flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            n--;
            if (n == 0) return true;
        }
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int len;
	cin>>len;
	vector<int> flowerbed;
	for(int i = 0; i < len; ++i) {
		int t;
		cin>>t;
		flowerbed.push_back(t);
	}
	int n;
	cin>>n;
	cout<<canPlaceFlowers(flowerbed, n);
	
	return 0;
}
