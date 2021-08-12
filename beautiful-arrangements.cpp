class Solution {
public:
    void countBeautifulPermutations(vector<int> &arr, int start, int &count) {
        if (start == arr.size())
            count++;
        
        for (int i = start; i < arr.size(); ++i) {
            swap(arr[start], arr[i]);
            if (arr[start] % (start + 1) == 0 or ((start + 1) % arr[start]) == 0)
                countBeautifulPermutations(arr, start + 1, count);
            swap(arr[start], arr[i]);
        }
    }
    
    int countArrangement(int n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i)
            arr[i] = i + 1;
        int count = 0;
        countBeautifulPermutations(arr, 0, count);
        return count;
    }
};
