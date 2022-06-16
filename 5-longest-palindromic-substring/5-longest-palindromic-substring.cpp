class Solution {
private:
    bool helper(int i, int j, string& s, vector<vector<int>>& dp, int& maxlen, int& start)
    {
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
        {
            dp[i][j] = helper(i+1,j-1,s,dp,maxlen,start);
        }
        else
        {
            dp[i][j]=false;
        }
        if(dp[i][j]==1)
        {
            if(maxlen < j-i+1)
            {
                maxlen=j-i+1;
                start=i;
            }
        }
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0, maxlen=0;
        
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                helper(i,j,s,dp,maxlen,start);
            }
        }
        return s.substr(start,maxlen);
        // pair<int,int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     string temp;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(dp[i][j]==true)
        //         {
        //             if(ans.second-ans.first + 1 <j-i+1)
        //             {
        //                 ans = {i,j};
        //             }
        //         }
        //     }
        // }
        // string res;
        // for(int i=ans.first;i<=ans.second;i++)
        // {
        //     res+=s[i];
        // }
        // return res;
        
    }
};