// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
// memoization
    int helper(int i, int j, int istrue, string& s, vector<vector<vector<int>>>& dp)
    {
        if(i==j)
        {
            if(istrue==1 && s[i]=='T') return 1;
            else if(istrue==0 && s[i]=='F') return 1;
            else return 0;
        }
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        int ways=0;
        for(int k = i+1;k<=j-1;k+=2)
        {
            int lt=helper(i,k-1,1,s,dp);
            int lf=helper(i,k-1,0,s,dp);
            int rt=helper(k+1,j,1,s,dp);
            int rf=helper(k+1,j,0,s,dp);
            if(s[k]=='&')
            {
                if(istrue==1)
                {
                    ways+=(lt*rt)%1003;
                }
                else
                {
                    ways+=(((lt*rf)%1003 + (lf*rt)%1003)%1003 + (lf*rf)%1003)%1003;
                }
            }
            else if(s[k]=='|')
            {
                if(istrue==1)
                {
                    ways+=(((lt*rf)%1003 + (lf*rt)%1003)%1003 + (lt*rt)%1003)%1003;
                }
                else
                {
                    ways+=(lf*rf)%1003;
                }
            }
            else
            {
                if(istrue==1)
                {
                    ways+=((lt*rf)%1003 + (lf*rt)%1003)%1003;
                }
                else
                {
                    ways+=((lf*rf)%1003 + (lt*rt)%1003)%1003;
                }
            }
        }
        return dp[i][j][istrue]=ways%1003;
    }
public:
    int countWays(int n, string s){
        
        // memoization
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2,-1)));
        // return helper(0,n-1,1,s,dp);
        
        // tabulation
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<=n-1;j++)
            {
                for(int t = 0;t<=1;t++)
                {
                    int ways=0;
                    if(i==j)
                    {
                        if(t==1) dp[i][j][t] = s[i]=='T';
                        else dp[i][j][t] = s[i]=='F';
                    }
                    else
                    {
                        for(int k=i+1;k<=j-1;k+=2)
                        {
                            int lt=dp[i][k-1][1];
                            int lf=dp[i][k-1][0];
                            int rt=dp[k+1][j][1];
                            int rf=dp[k+1][j][0];
                            if(s[k]=='&')
                            {
                                if(t==1)
                                {
                                    ways+=(lt*rt)%1003;
                                }
                                else
                                {
                                    ways+=(((lt*rf)%1003 + (lf*rt)%1003)%1003 + (lf*rf)%1003)%1003;
                                }
                            }
                            else if(s[k]=='|')
                            {
                                if(t==1)
                                {
                                    ways+=(((lt*rf)%1003 + (lf*rt)%1003)%1003 + (lt*rt)%1003)%1003;
                                }
                                else
                                {
                                    ways+=(lf*rf)%1003;
                                }
                            }
                            else
                            {
                                if(t==1)
                                {
                                    ways+=((lt*rf)%1003 + (lf*rt)%1003)%1003;
                                }
                                else
                                {
                                    ways+=((lf*rf)%1003 + (lt*rt)%1003)%1003;
                                }
                            }
                        }
                        dp[i][j][t]=ways%1003;
                    }
                }
            }
        }
        return dp[0][n-1][1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends