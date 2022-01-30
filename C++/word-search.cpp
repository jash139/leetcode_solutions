class Solution {
public:
     bool dfs(vector<vector<char>> &board, int row, int col, string word, int curIdx) {
         if (curIdx == word.size())
             return true;
         if (row < 0 or col < 0 or row >= board.size() or col >= board[0].size() or board[row][col] == '*')
             return false;
         
         if (board[row][col] == word[curIdx]) {
             board[row][col] = '*';
             bool returnValue =
                 dfs(board, row + 1, col, word, curIdx + 1) or 
                 dfs(board, row - 1, col, word, curIdx + 1) or 
                 dfs(board, row, col + 1, word, curIdx + 1) or 
                 dfs(board, row, col - 1, word, curIdx + 1);
                 
             board[row][col] = word[curIdx];
             return returnValue;
         } else {
             return false;
         }
         
     }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
