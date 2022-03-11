class Solution:
    def firstUniqChar(self, s: str) -> int:
        charCount = {}

        for ch in s:
            if ch not in charCount:
                charCount[ch] = 0
            charCount[ch] += 1

        for i in range(0, len(s)):
            if charCount[s[i]] == 1:
                return i

        return -1