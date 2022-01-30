#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(nlog(n)) Time | O(n) Space
    // n : number of intervals in input array
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        
        vector<vector<int>> mergedIntervals;
        int idx = 0;
        
        while (idx < intervals.size()) {
            int start = intervals[idx][0];
            int end = intervals[idx][1];
            int nextIdx = idx + 1;
            while (nextIdx < intervals.size() and intervals[nextIdx][0] <= end) {
                end = max(end, intervals[nextIdx][1]);
                nextIdx++;
            }
            mergedIntervals.push_back({start, end});
            idx = nextIdx;
        }
        
        return mergedIntervals;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// Add driver code
	
	return 0;
}
