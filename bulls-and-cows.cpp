class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        unordered_map<char, int> potentialCowsCount;
        unordered_map<char, int> potentialBullsCount;
        
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                potentialCowsCount[secret[i]]++;
                potentialBullsCount[guess[i]]++;
            }
        }
        
        for (auto ele : potentialBullsCount) {
            if (potentialCowsCount.find(ele.first) != potentialCowsCount.end()) {
                cows += min(potentialCowsCount[ele.first], ele.second);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
