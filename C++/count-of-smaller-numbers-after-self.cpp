class Solution {
public:
    void merge(vector<int> &counts, vector<pair<int, int>> &v, int start, int mid, int end) {
        vector<pair<int, int>> tmp(end - start + 1);
        
        int i = start;
        int j = mid+1;
        int k = 0;

        while (i <= mid and j <= end) {
            if (v[i].first <= v[j].first) {
                tmp[k++] = v[j++];
            }
            else {
                counts[v[i].second] += end - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        while (j <= end) {
            tmp[k++] = v[j++];
        }
        for (int i = start; i <= end; i++)
            v[i] = tmp[i-start];
    }        

    void mergeSort(vector<int> &counts, vector<pair<int, int> > &v, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        
        mergeSort(counts, v, start, mid);
        mergeSort(counts, v, mid + 1, end);
        
        merge(counts, v, start, mid, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            v[i] = make_pair(nums[i], i);
        }

        vector<int> counts(nums.size(), 0);
        
        mergeSort(counts, v, 0, nums.size() - 1);

        return counts;
    }
};
