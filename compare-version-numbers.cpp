class Solution {
public:
    void getVersionValues(string version, vector<int> &versionVals) {
        string curr = "";
        for (int i = 0; i < version.size(); ++i) {
            if (version[i] == '.') {
                versionVals.push_back(stoi(curr));
                curr = "";
            } else {
                curr.push_back(version[i]);
            }
        }
        versionVals.push_back(stoi(curr));
    }
    
    int isVersionGreater(vector<int> version1Vals, vector<int> version2Vals) {
        int size1 = version1Vals.size();
        int size2 = version2Vals.size();
        
        int idx = 0;
        
        while (idx < size1 and idx < size2) {
            if (version1Vals[idx] < version2Vals[idx]) {
                return -1;
            } else if (version1Vals[idx] > version2Vals[idx]) {
                return 1;
            }
            idx++;
        }
        
        int currIdx = idx;
        while (currIdx < size1) {
            if (version1Vals[currIdx] > 0)
                return 1;
            currIdx++;
        }
        currIdx = idx;
        while (currIdx < size2) {
            if (version2Vals[currIdx] > 0)
                return -1;
            currIdx++;
        }
        
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> version1Vals;
        vector<int> version2Vals;
        
        getVersionValues(version1, version1Vals);
        getVersionValues(version2, version2Vals);
       
        return isVersionGreater(version1Vals, version2Vals);
    }
};
