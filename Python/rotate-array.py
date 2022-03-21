class Solution:
    # Using reverse
    # Reverse whole array
    # Reverse first k numbers
    # Reverse last n - k numbers
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k == 0:
            return
        k = k % len(nums)
        end = len(nums) - 1

        self.reverseInRange(nums, 0, end - k)
        self.reverseInRange(nums, end - k + 1, end)
        self.reverseInRange(nums, 0, end)

    def reverseInRange(self, nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

# ---------------------------------------------------------------------------------

class Solution:
    # Using extra space
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        idx = 0
        numsCopy = nums[:]

        for i in range(0, n):
            pos = (i + k) % n
            nums[pos] = numsCopy[idx]
            idx += 1