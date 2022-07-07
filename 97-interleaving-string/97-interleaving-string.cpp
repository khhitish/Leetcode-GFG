class Solution {
private:
    // // memoization
    // bool helper(int i, string& s1, int j, string& s2, int k, string& s3,vector<vector<int>>& dp)
    // {
    //     if(i<0)
    //     {
    //         if(s2.substr(0,j+1)==s3.substr(0,k+1)) return true;
    //         else return false;
    //     }
    //     else if(j<0)
    //     {
    //         if(s1.substr(0,i+1)==s3.substr(0,k+1)) return true;
    //         else return false;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(s1[i]==s3[k] && helper(i-1,s1,j,s2,k-1,s3,dp)==true) ans=true;
    //     else if(s2[j]==s3[k] && helper(i,s1,j-1,s2,k-1,s3,dp)==true) ans=true;
    //     return dp[i][j]=ans;
    // }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size(), o=s3.size();
        if(o!=m+n) return false;
        
        // // memoization
        // vector<vector<int>> dp(m, vector<int> (n,-1));
        // return helper(m-1,s1,n-1,s2,o-1,s3,dp);
        
        // tabulation
        // vector<vector<bool>> dp(m+1, vector<bool> (n+1,false));
        // // if(dp[i-1][j] is true that means we have matched upto i-2th index of s1 and j-1th index of s2 because of index shifting) which means the index of s3 upto which we have matched will be: i-1+j letters means i+j-2th index, so now we need to match i+j-1th index
        // //if i=0,j=0 then we have reached this point after matching everything hence true
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         if(i==0 && j==0) dp[i][j]=true;
        //         else if(i==0)
        //         {
        //             if(dp[i][j-1]==true && s2[j-1]==s3[i+j-1]) dp[i][j]=true;
        //         }
        //         else if(j==0)
        //         {
        //             if(dp[i-1][j]==true && s1[i-1]==s3[i+j-1]) dp[i][j]=true;
        //         }
        //         else
        //         {
        //             if((dp[i-1][j]==true && s1[i-1]==s3[i+j-1]) || 
        //                (dp[i][j-1]==true && s2[j-1]==s3[i+j-1]))
        //                 dp[i][j]=true;
        //         }
        //     }
        // }
        // return dp[m][n];
        
        // space optimised tabulation
        vector<bool> dp(n+1,false);
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 && j==0) dp[j]=true;
                else if(i==0)
                {
                    if(dp[j-1]==true && s2[j-1]==s3[i+j-1]) dp[j]=true;
                    else dp[j]=false;
                }
                else if(j==0)
                {
                    if(dp[j]==true && s1[i-1]==s3[i+j-1]) dp[j]=true;
                    else dp[j]=false;
                }
                else
                {
                    if((dp[j]==true && s1[i-1]==s3[i+j-1]) || 
                       (dp[j-1]==true && s2[j-1]==s3[i+j-1]))
                        dp[j]=true;
                    else dp[j]=false;
                }
            }
        }
        return dp[n];
    }
};