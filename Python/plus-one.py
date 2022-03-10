class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        originalLength = len(digits)
        result = [0] * originalLength

        idx = originalLength - 1

        while idx >= 0 and digits[idx] == 9:
            result[idx] = 0
            idx -= 1

        if idx < 0:
            result = [1] + result
        else:
            result[idx] += 1

        while (idx >= 0):
            result[idx] += digits[idx];
            idx -= 1

        return result