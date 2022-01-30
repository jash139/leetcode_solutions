class Solution {
    unordered_map<string, vector<string>> memo;
    
public:
    vector<string> combine(string word, vector<string> prev){
        for (int i = 0; i < prev.size(); ++i){
            prev[i] += " " + word;
        }
        
        return prev;
    }

    vector<string> getSentences(string s, unordered_set<string> dict) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        
        if (dict.find(s) != dict.end()){
            result.push_back(s);
        }
        
        for(int i = 1; i < s.size(); ++i){
            string word = s.substr(i);
            
            if (dict.find(word) != dict.end()) {
                string rem = s.substr(0,i);
                vector<string> prev = combine(word, getSentences(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        
        memo[s] = result;
        
        return memo[s];
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        unordered_set<string> dictionary;
        
        for (auto word : dict) {
            dictionary.insert(word);
        }
        
        return getSentences(s, dictionary);
    }
};
