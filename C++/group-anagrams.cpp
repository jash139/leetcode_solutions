class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> allAnagrams;
        unordered_map<string, vector<string>> anagrams;
        
        for (int idx = 0; idx < strs.size(); ++idx) {
            string sortedStr = strs[idx];
            
            sort(sortedStr.begin(), sortedStr.end());
            if (anagrams.find(sortedStr) == anagrams.end())
                anagrams[sortedStr] = vector<string> {};
            anagrams[sortedStr].push_back(strs[idx]);
        }
        
        for (auto anagram : anagrams)
            allAnagrams.push_back(anagram.second);
        return allAnagrams;
    }
};
