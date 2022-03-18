class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            middle = left + (right - left) // 2
            potentialMatch = nums[middle]
            leftNum = nums[left]
            rightNum = nums[right]

            if potentialMatch == target:
                return middle
            elif leftNum <= potentialMatch:
                if target >= leftNum and target < potentialMatch:
                    right = middle - 1
                else:
                    left = middle + 1
            else:
                if target <= rightNum and target > potentialMatch:
                    left = middle + 1
                else:
                    right = middle - 1

        return -1