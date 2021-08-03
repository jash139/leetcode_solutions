class Solution {
public:
    vector<int> getLongestPalindromeFrom(string str, int leftIdx, int rightIdx) {
        while (leftIdx >= 0 and rightIdx < str.length() and str[leftIdx] == str[rightIdx]) {
            leftIdx--;
            rightIdx++;
        }
        return vector<int> {leftIdx + 1, rightIdx};
    }
    // O(n ^ 2) Time | O(n) Space
    // n : length of the string
    string longestPalindrome(string s) {
        vector<int> currentLongest{0, 1};
        for (int idx = 1; idx < s.length(); ++idx) {
            vector<int> odd = getLongestPalindromeFrom(s, idx - 1, idx + 1);
            vector<int> even = getLongestPalindromeFrom(s, idx - 1, idx);
            
            vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
            currentLongest = longest[1] - longest[0] > currentLongest[1] - currentLongest[0] ? longest : currentLongest;
        }
        return s.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
    }
};
