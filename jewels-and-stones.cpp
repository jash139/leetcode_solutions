#include<bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    int jlen = jewels.length();
    int slen = stones.length();
    unordered_map<char, bool> isJewel;
    for(int i = 0; i < jlen; ++i) {
        isJewel[jewels[i]] = true;
    }
    int ans = 0;
    for(int i = 0; i < slen; ++i) {
        if (!(isJewel.find(stones[i]) == isJewel.end())) {
            ans++;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string jewels, stones;
	cin>>jewels>>stones;
	cout<<numJewelsInStones(jewels, stones);
	
	return 0;
}
