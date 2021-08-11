class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &interval1, vector<int> &interval2) {return interval1[1] < interval2[1];});
        int count = 0;
        int prev = 0;
        
        for (int i = 1; i < intervals.size(); ++i)
            if (intervals[prev][1] > intervals[i][0])
                count++;
            else
                prev = i;
        
        return count;
    }
};
