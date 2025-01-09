#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateRow(vector<vector<char>>& board, int row) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            char val = board[row][i];
            if (val != '.' && (val < '1' || val > '9' || seen.count(val))) {
                return false;
            }
            seen.insert(val);
        }
        return true;
    }

    bool validateColumn(vector<vector<char>>& board, int col) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            char val = board[i][col];
            if (val != '.' && (val < '1' || val > '9' || seen.count(val))) {
                return false;
            }
            seen.insert(val);
        }
        return true;
    }

    bool validateSubBoxes(int startRow, int startCol, vector<vector<char>>& board) {
        unordered_set<char> seen;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                char val = board[i][j];
                if (val != '.' && (val < '1' || val > '9' || seen.count(val))) {
                    return false;
                }
                seen.insert(val);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!validateRow(board, i) || !validateColumn(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!validateSubBoxes(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    cout<<s.isValidSudoku(board)<<endl;
};