class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        givenSum = 0
        for num in nums:
            givenSum += num

        return (len(nums) * (len(nums) + 1)) // 2 - givenSum