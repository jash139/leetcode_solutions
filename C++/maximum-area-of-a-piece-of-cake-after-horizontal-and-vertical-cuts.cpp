class Solution {
public:
    int getMaxDistance(int totalDist, vector<int> cuts) {
        sort(cuts.begin(), cuts.end());
        int maxDist = max(totalDist - cuts[cuts.size() - 1], cuts[0]);
        
        for (int i = 1; i < cuts.size(); ++i) {
            maxDist = max(maxDist, cuts[i] - cuts[i - 1]);
        }
        
        return maxDist;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxHorizontal = getMaxDistance(h, horizontalCuts);
        int maxVertical = getMaxDistance(w, verticalCuts);
        
        return (int)(((long)maxHorizontal * maxVertical) % 1000000007);
    }
};
