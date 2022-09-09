class Solution {
private:
    bool helper(int idx, int i, int j, string& word, vector<vector<char>>& board, vector<int> &dir)
    {
        if(idx==word.size()) return true;
        int m=board.size(), n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx]) return false;
        board[i][j]='#';
        
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k], y=j+dir[k+1];
            if(helper(idx+1,x,y,word,board,dir)==true) return true;
        }
        board[i][j]=word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<int> dir={0,1,0,-1,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])if(helper(0,i,j,word,board,dir)==true) return true;
            }
        }
        return false;
    }
};