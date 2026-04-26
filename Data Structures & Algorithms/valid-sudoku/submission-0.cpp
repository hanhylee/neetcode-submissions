class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (const auto& row: board) {
            if (!isValidSudokuSection(row)) return false;
        }

        // check cols
        for (int i=0; i<board.size(); i++) {
            vector<char> col = {
                board[0][i], board[1][i], board[2][i],
                board[3][i], board[4][i], board[5][i],
                board[6][i], board[7][i], board[8][i],
            };
            if (!isValidSudokuSection(col)) return false;
        }

        // check boxes
        vector<pair<int,int>> valid_centers = {
            pair<int,int>(1,1), pair<int,int>(4,1), pair<int,int>(7,1),
            pair<int,int>(1,4), pair<int,int>(4,4), pair<int,int>(7,4),
            pair<int,int>(1,7), pair<int,int>(4,7), pair<int,int>(7,7),
        };
        for (const auto& center: valid_centers) {
            int x = center.first;
            int y = center.second;
            vector<char> box = {
                board[y-1][x-1], board[y-1][x], board[y-1][x+1],
                board[y][x-1], board[y][x], board[y][x+1],
                board[y+1][x-1], board[y+1][x], board[y+1][x+1],
            };
            if (!isValidSudokuSection(box)) return false;
        }

        return true;
    }

    bool isValidSudokuSection(const vector<char>& section) {
        unordered_set<char> valid_chars = {
            '1', '2', '3', '4', '5', '6', '7', '8', '9'
        };
        unordered_set<char> visited;

        for (const char& c: section) {
            if (c == '.') continue;
            if (valid_chars.find(c) == valid_chars.end()) return false;
            if (visited.find(c) == visited.end()) {
                visited.insert(c);
            } else {
                return false;
            }
        }

        return true;
    }
};
