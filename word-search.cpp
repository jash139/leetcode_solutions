class Solution {
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string word) {
        if (word.size() == 0)
            return true;
        if (i < 0 or i >= board.size() or  j < 0 or j >= board[0].size() or board[i][j] != word[0])
            return false;
        
        char ch = board[i][j];
        board[i][j] = '*';
        string substr = word.substr(1);
        
        bool returnValue = dfs(board, i - 1, j, substr) or dfs(board, i + 1, j, substr) or dfs(board, i, j - 1, substr) or dfs(board, i, j + 1, substr);
        
        board[i][j] = ch;
        return returnValue;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
};
