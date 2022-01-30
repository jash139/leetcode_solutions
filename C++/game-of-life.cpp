class Solution {
public:
    int getLiveNeighbors(int row, int col, vector<vector<int>> board) {
        int count = 0;
        
        if (row - 1 >= 0 and col - 1 >= 0 and board[row - 1][col - 1] == 1)
            count++;
        if (row + 1 < board.size() and col + 1 < board[0].size() and board[row + 1][col + 1] == 1)
            count++;
        if (row - 1 >= 0 and col + 1 < board[0].size() and board[row - 1][col + 1] == 1)
            count++;
        if (row + 1 < board.size() and col - 1 >= 0 and board[row + 1][col - 1] == 1)
            count++;
        if (row - 1 >= 0 and board[row - 1][col] == 1)
            count++;
        if (row + 1 < board.size() and board[row + 1][col] == 1)
            count++;
        if (col - 1 >= 0 and board[row][col - 1] == 1)
            count++;
        if (col + 1 < board[0].size() and board[row][col + 1] == 1)
            count++;
        
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> flipIdxs;
        
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                int liveNeighbors = getLiveNeighbors(row, col, board);
                if (board[row][col] == 0 and liveNeighbors == 3)
                    flipIdxs.push_back(vector<int>{ row, col });
                else if (board[row][col] == 1) {
                    if (liveNeighbors < 2)
                        flipIdxs.push_back(vector<int>{ row, col });
                    else if (liveNeighbors == 2 or liveNeighbors == 3)
                        continue;
                    else if (liveNeighbors > 3)
                        flipIdxs.push_back(vector<int>{ row, col });
                }
            }
        }
        
        for (auto idxs : flipIdxs) {
            int row = idxs[0];
            int col = idxs[1];
            board[row][col] = !board[row][col];
        }
    }
};
