//Link: https://leetcode.com/problems/n-queens/description/
/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

/*
Ist position: This is the position where we can see no possible arrangement is found where all queens can be placed since, 
at the 3rd column, the Queen will be killed at all possible positions of row.

2nd position: One of the correct possible arrangements is found. So we will store it as our answer.

3rd position: One of the correct possible arrangements is found. So we will store it as our answer.

4th position: This is the position where we can see no possible arrangement is found where all queens can be placed since, 
at the 4th column, the Queen will be killed at all possible positions of row.
TC: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
SC: O(N^2)
*/

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int tmpRow = row, tmpCol = col;
        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        col = tmpCol, row = tmpRow;
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        col = tmpCol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void helper(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                helper(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n);
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        helper(0, board, ans, n);
        return ans;
    }
};
