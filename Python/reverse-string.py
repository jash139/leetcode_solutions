class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for startIdx in range(0, len(s) // 2):
            endIdx = len(s) - startIdx - 1
            temp = s[startIdx]
            s[startIdx] = s[endIdx]
            s[endIdx] = temp