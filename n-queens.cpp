class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> validPositions;
        
        unordered_map<int, int> blockedColumns;
        unordered_set<int> blockedUpDiagonals;
        unordered_set<int> blockedDownDiagonals;
        string blankRow = "";
        for (int i = 0; i < n; ++i) {
            blankRow.push_back('.');
        }
        vector<string> position(n, blankRow);

        getNonAttackingPlacements(0, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, n, position, validPositions);
        
        return validPositions;
    }
    
    void getNonAttackingPlacements(int row, unordered_map<int, int> &blockedColumns, unordered_set<int> &blockedUpDiagonals, unordered_set<int> &blockedDownDiagonals, int n, vector<string> &position, vector<vector<string>> &validPositions) {
        if (row == n) {
            validPositions.push_back(position);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValidPosition(row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals)) {
                placeQueen(row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, position);
                getNonAttackingPlacements(row + 1, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, n, position, validPositions);
                removeQueen(row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, position);
            }
        }
    }
    
    bool isValidPosition(int row, int col, unordered_map<int, int> &blockedColumns, unordered_set<int> &blockedUpDiagonals, unordered_set<int> &blockedDownDiagonals) {
        if (blockedColumns.find(col) != blockedColumns.end())
            return false;
        if (blockedUpDiagonals.find(row + col) != blockedUpDiagonals.end())
            return false;
        if (blockedDownDiagonals.find(row - col) != blockedDownDiagonals.end())
            return false;
        
        return true;
    }
    
    void placeQueen(int row, int col, unordered_map<int, int> &blockedColumns, unordered_set<int> &blockedUpDiagonals, unordered_set<int> &blockedDownDiagonals, vector<string> &position) {
        blockedColumns[col] = row;
        blockedUpDiagonals.insert(row + col);
        blockedDownDiagonals.insert(row - col);
        position[row][col] = 'Q';
    }
    
    void removeQueen(int row, int col, unordered_map<int, int> &blockedColumns, unordered_set<int> &blockedUpDiagonals, unordered_set<int> &blockedDownDiagonals, vector<string> &position) {
        blockedColumns.erase(col);
        blockedUpDiagonals.erase(row + col);
        blockedDownDiagonals.erase(row - col);
        position[row][col] = '.';
    }
};
