class Solution {
private:
    // // memoization
    // bool helper(int i, int j, string& s, vector<vector<int>>& dp, int& maxlen, int& start)
    // {
    //     if(i>j) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j])
    //     {
    //         dp[i][j] = helper(i+1,j-1,s,dp,maxlen,start);
    //     }
    //     else
    //     {
    //         dp[i][j]=false;
    //     }
    //     if(dp[i][j]==1)
    //     {
    //         if(maxlen < j-i+1)
    //         {
    //             maxlen=j-i+1;
    //             start=i;
    //         }
    //     }
    //     return dp[i][j];
    // }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0, maxlen=1;
        
        // // memoization way of precomputing palindromes and simultaneously getting our ans
        // // Time = O(n^2) Space = O(n^2)
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         helper(i,j,s,dp,maxlen,start);
        //     }
        // }
        // return s.substr(start,maxlen);
        
        
        // tabulation way of precomputing palindromes and simultaneously getting our ans
        // Time = O(n^2) Space = O(n^2)
        vector<vector<bool>> dp(n, vector<bool> (n,false));
        for(int i=0;i<n;i++) // base cases (i,i) & (i,i+1)
        {
            dp[i][i]=true; // length 1 substrings
            int j=i+1;
            if(j<n) // length 2 substrings
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(maxlen<j-i+1)
                    {
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        for(int len=3;len<=n;len++) // length 3 onwards, we have to do it in the increasing order of length so that we can use the previous results in calculating curr results
        {
            for(int i=0;i<n-len+1;i++)//so that j doesnt go out of bounds
            {
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                {
                    dp[i][j]=true;
                    if(maxlen<j-i+1)
                    {
                        maxlen=j-i+1;
                        start=i;
                    }
                }
                else
                {
                    dp[i][j]=false;
                }
                
            }
        }
        return s.substr(start,maxlen);
    }
};