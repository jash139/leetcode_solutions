class Solution {
public:
    bool isMatch(string s, string p) {
        auto matchTable = initializeMatchTable(s, p);
        for (auto i = 1; i <= s.size(); ++i) {
            for (auto j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    matchTable[i][j] = matchTable[i][j - 1] or matchTable[i - 1][j];
                } else if (p[j - 1] == '?' or p[j - 1] == s[i - 1]) {
                    matchTable[i][j] = matchTable[i - 1][j - 1];
                }
            }
        }

        return matchTable[s.size()][p.size()];
    }

    vector<vector<bool>> initializeMatchTable(string s, string p) {
        vector<vector<bool>> matchTable = {};
        for (auto i = 0; i <= s.size(); ++i) {
            vector<bool> row = {};
            for (auto j = 0; j <= p.size(); ++j) {
                row.push_back(false);
            }
            matchTable.push_back(row);
        }

        matchTable[0][0] = true;

        for (auto j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*')
                matchTable[0][j] = matchTable[0][j - 1];
        }

        return matchTable;
    }
};
