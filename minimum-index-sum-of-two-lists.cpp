class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> commonInterest;
        
        unordered_map<string, int> list1Map;
        for (int i = 0; i < list1.size(); ++i) {
            list1Map[list1[i]] = i;
        }
        
        unordered_map<string, int> commonInterestMap;
        
        int minIndexSum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            string curRes = list2[i];
            
            if (list1Map.find(curRes) != list1Map.end()) {
                minIndexSum = min(minIndexSum, i + list1Map[curRes]);
                commonInterestMap[curRes] = i + list1Map[curRes];
            }
        }
        
        for (auto it : commonInterestMap) {
            if (it.second == minIndexSum) {
                commonInterest.push_back(it.first);
            }
        }
        
        return commonInterest;
    }
};
