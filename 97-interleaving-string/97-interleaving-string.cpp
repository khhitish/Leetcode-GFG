class Solution {
private:
    bool helper(int i, string& s1, int j, string& s2, int k, string& s3,vector<vector<int>>& dp)
    {
        if(i<0)
        {
            if(s2.substr(0,j+1)==s3.substr(0,k+1)) return true;
            else return false;
        }
        else if(j<0)
        {
            if(s1.substr(0,i+1)==s3.substr(0,k+1)) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(s1[i]==s3[k] && helper(i-1,s1,j,s2,k-1,s3,dp)==true) ans=true;
        else if(s2[j]==s3[k] && helper(i,s1,j-1,s2,k-1,s3,dp)==true) ans=true;
        return dp[i][j]=ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size(), o=s3.size();
        if(o!=m+n) return false;
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return helper(m-1,s1,n-1,s2,o-1,s3,dp);
    }
};