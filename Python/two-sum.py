class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        alreadyVisitedIndices = {}

        for index, num in enumerate(nums):
            if (target - num) in alreadyVisitedIndices:
                return [alreadyVisitedIndices[target - num], index]
            else:
                alreadyVisitedIndices[num] = index;

        return []