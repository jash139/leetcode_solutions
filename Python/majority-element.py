class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numsLen = len(nums)
        numCount = {}

        for num in nums:
            if num not in numCount:
                numCount[num] = 0
            numCount[num] += 1

        for num in numCount:
            if numCount[num] > numsLen / 2:
                return num

        return -1