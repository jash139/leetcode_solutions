class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> maxNumbers1 = createMaxNumbersOfDiffLengths(nums1, k);
        vector<vector<int>> maxNumbers2 = createMaxNumbersOfDiffLengths(nums2, k);
        
        vector<int> result;
        
        for (int idx = 0; idx <= k; ++idx) {
            if (maxNumbers1[idx].size() + maxNumbers2[k - idx].size() < k) {
                continue;
            }
            
            vector<int> temp = mergeArrays(maxNumbers1[idx], maxNumbers2[k - idx]);
            result = maxArray(result, temp);
        }
        
        return result;
    }
    
    vector<vector<int>> createMaxNumbersOfDiffLengths(vector<int> array, int length) {
        vector<vector<int>> maxNumbers(length + 1);
        int idx;
        int start;
        
        for (start = 0; array.size() > 0; start = (idx == 0 ? 0 : idx - 1)) {
            if (array.size() <= length) {
                maxNumbers[array.size()] = array;
            }
            idx = start;
            while (idx + 1 < array.size() and array[idx] >= array[idx + 1]) {
                idx++;
            }
            array.erase(array.begin() + idx);
        }
        
        return maxNumbers;
    }
    
    vector<int> mergeArrays(vector<int> array1, vector<int> array2) {
        vector<int> mergedArray(array1.size() + array2.size(), 0);
        for (int i = 0, j = 0, r = 0; r < array1.size() + array2.size(); ++r) {
            mergedArray[r] = isGreaterAt(array1, i, array2, j) ? array1[i++] : array2[j++];
        }
        
        return mergedArray;
    }
    
    bool isGreaterAt(vector<int> array1, int i, vector<int> array2, int j) {
        while (i < array1.size() and j < array2.size() and array1[i] == array2[j]) {
            i++;
            j++;
        }
        
        return j == array2.size() or (i < array1.size() and array1[i] > array2[j]);
    }
    
    vector<int> maxArray(vector<int> array1, vector<int> array2) {
        if (array1.size() == 0)
            return array2;
        else if (array2.size() == 0)
            return array2;
        
        for (int i = 0; i < array1.size(); ++i) {
            if (array1[i] < array2[i])
                return array2;
            else if (array1[i] > array2[i])
                return array1;
        }
            
        return array1;
    }
};
