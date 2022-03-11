class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sCharCount = {}
        tCharCount = {}

        for ch in s:
            if ch not in sCharCount:
                sCharCount[ch] = 0

            sCharCount[ch] += 1

        for ch in t:
            if ch not in tCharCount:
                tCharCount[ch] = 0

            tCharCount[ch] += 1

        for ch in sCharCount:
            if ch not in tCharCount or sCharCount[ch] != tCharCount[ch]:
                return False

        return len(sCharCount) == len(tCharCount)