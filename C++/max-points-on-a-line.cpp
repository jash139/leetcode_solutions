class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxNumberOfPointsOnLine = 1;
        
        for (int idx1 = 0; idx1 < points.size(); ++idx1) {
            auto p1 = points[idx1];
            unordered_map<string, int> slopes;
            
            for (int idx2 = idx1 + 1; idx2 < points.size(); ++idx2) {
                auto p2 = points[idx2];
                
                auto slope = getSlopeOfLineBetweenPoints(p1, p2);
                int rise = slope[0];
                int run = slope[1];
                
                string slopeKey = createHashableKeyForRational(rise, run);
                if (slopes.find(slopeKey) == slopes.end()) {
                    slopes[slopeKey] = 1;
                }
                slopes[slopeKey]++;
                maxNumberOfPointsOnLine = max(maxNumberOfPointsOnLine, slopes[slopeKey]);
            }
        }
        
        return maxNumberOfPointsOnLine;
    }
    
    vector<int> getSlopeOfLineBetweenPoints(vector<int> p1, vector<int> p2) {
        int p1x = p1[0];
        int p1y = p1[1];
        int p2x = p2[0];
        int p2y = p2[1];
        vector<int> slope = {1, 0};
        
        if (p1x != p2x) {
            int xDiff = p1x - p2x;
            int yDiff = p1y - p2y;
            
            int gcd = getGreatestCommonDivisor(abs(xDiff), abs(yDiff));
            
            xDiff /= gcd;
            yDiff /= gcd;
            
            if (xDiff < 0) {
                xDiff *= -1;
                yDiff *= -1;
            }
            
            slope = {yDiff, xDiff};
        }
        
        return slope;
    }
    
    string createHashableKeyForRational(int numerator, int denominator) {
        return to_string(numerator) + "/" + to_string(denominator);
    }
    
    int getGreatestCommonDivisor(int num1, int num2) {
        while (true) {
            if (num1 == 0)
                return num2;
            if (num2 == 0)
                return num1;
            
            int temp = num1;
            num1 = num2;
            num2 = temp % num2;
        }
    }
};
