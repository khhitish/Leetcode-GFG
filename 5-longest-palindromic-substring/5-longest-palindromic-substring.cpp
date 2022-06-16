class Solution {
private:
    bool helper(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
        {
            dp[i][j] = helper(i+1,j-1,s,dp);
        }
        else
        {
            dp[i][j]=false;
        }
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(s[i]==s[j])
        //         {
        //             int x=i+1, y=j-1;
        //             if(x<y || x>=n || j<0)
        //             {
        //                 dp[i][j]=true;
        //             }
        //             else
        //             {
        //                 if(dp[x][y]==true) dp[i][j]=true;
        //             }
        //         }
        //         else
        //         {
        //             dp[i][j]=false;
        //         }
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                helper(i,j,s,dp);
            }
        }
        pair<int,int> ans;
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=i+1;j<n;j++)
            {
                if(dp[i][j]==true)
                {
                    if(ans.second-ans.first + 1 <j-i+1)
                    {
                        ans = {i,j};
                    }
                }
            }
        }
        string res;
        for(int i=ans.first;i<=ans.second;i++)
        {
            res+=s[i];
        }
        return res;
        
    }
};