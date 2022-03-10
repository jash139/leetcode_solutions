class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        isPresent = {}

        for num in nums:
            if num in isPresent:
                return True
            isPresent[num] = True

        return False