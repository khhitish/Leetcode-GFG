class Solution {
private:
    bool helper(int i, int j, int idx, string& word, vector<vector<char>>& board)
    {
        
        int m=board.size(), n=board[0].size(), sz = word.size();
        if(idx==sz) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx]) return false;
        board[i][j] = '#';
        vector<int> dir = {0,-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int row = i + dir[k], col = j+ dir[k+1];
            if(helper(row,col,idx+1,word,board)==true) return true;
        }
        board[i][j] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(helper(i,j,0,word,board)==true) return true;
                }
            }
        }
        return false;
    }
};