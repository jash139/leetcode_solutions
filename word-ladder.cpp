class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary;
        for (auto word : wordList) {
            dictionary.insert(word);
        }
        
        int seqLength = 1;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            int len = q.size();
            
            for (int i = 0; i < len; ++i) {
                string curWord = q.front();
                q.pop();

                if (curWord == endWord) {
                    return seqLength;
                }
                
                dictionary.erase(curWord);
                
                for (int j = 0; j < curWord.size(); ++j) {
                    char ch = curWord[j];
                    
                    for (int k = 0; k < 26; ++k) {
                        curWord[j] = 'a' + k;
                        if (dictionary.find(curWord) != dictionary.end()) {
                            q.push(curWord);
                        }
                    }
                    curWord[j] = ch;
                }
                
            }
            
            seqLength++;
        }
        
        return 0;
    }
};
