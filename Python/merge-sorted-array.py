class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        mergedArray = [0] * (m + n)

        i = 0
        j = 0

        while i + j <= m + n and i < m and j < n:
            if (nums1[i] < nums2[j]):
                mergedArray[i + j] = nums1[i]
                i += 1
            else:
                mergedArray[i + j] = nums2[j]
                j += 1

        while i < m:
            mergedArray[i + j] = nums1[i]
            i += 1

        while j < n:
            mergedArray[i + j] = nums2[j]
            j += 1

        for k in range(0, m + n):
            nums1[k] = mergedArray[k]