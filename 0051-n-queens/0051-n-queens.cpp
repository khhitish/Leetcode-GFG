class Solution {
private:
    void helper(int col, vector<int>& rowhash, vector<int>& upperdia, vector<int>& lowerdia, vector<string>& board, vector<vector<string>>& ans) {
        int n = board.size();
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(rowhash[row] == 0 && upperdia[row-col+n-1] == 0 && lowerdia[row+col] == 0) {
                board[row][col] = 'Q';
                rowhash[row] = 1;
                upperdia[row-col+n-1] = 1;
                lowerdia[row+col] = 1;
                helper(col+1,rowhash,upperdia,lowerdia,board,ans);
                board[row][col] = '.';
                rowhash[row] = 0;
                upperdia[row-col+n-1] = 0;
                lowerdia[row+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string (n,'.'));
        vector<int> rowhash(n,0);
        vector<int> upperdia(2*n-1,0);
        vector<int> lowerdia(2*n-1,0);
        vector<vector<string>> ans;
        helper(0,rowhash,upperdia,lowerdia,board,ans);
        return ans;
    }
};