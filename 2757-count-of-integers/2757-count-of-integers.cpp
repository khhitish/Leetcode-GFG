class Solution {
private:
    int helper(int i, int digitsum, int equal, string& num1, vector<vector<vector<int>>>& dp, int mod){
        if(digitsum == 0 || i==num1.size()) return 1;
        if(dp[i][digitsum][equal]!=-1) return dp[i][digitsum][equal];
        int ans = 0;
        int maxi = 9;
        if(equal == 1) maxi = num1[i] - '0';
        for(int num = 0;num<=maxi && num<=digitsum;num++) {
            int flag = 0;
            if(equal == 1 && num == maxi)flag = 1;
            ans= (ans + helper(i+1,digitsum-num,flag,num1,dp,mod))%mod;
        }
        return dp[i][digitsum][equal] = ans;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        string maxnum = num2;
        string minnum = num1;
        int i = minnum.size()-1;
        while(i>=0 && minnum[i] == '0'){
            minnum[i--] = '9';
        }
        int mod = 1e9 + 7;
        minnum[i]--;
        int maxsum = max_sum;
        int minsum = min_sum - 1;
        vector<vector<vector<int>>> dpupper(maxnum.size(), vector<vector<int>> (maxsum+1, vector<int> (2, -1)));
        vector<vector<vector<int>>> dplower(minnum.size(), vector<vector<int>> (maxsum+1, vector<int> (2, -1)));
        int upper = (helper(0,maxsum,1,maxnum,dpupper,mod) - helper(0,maxsum,1,minnum,dplower,mod))%mod;
        int lower = (helper(0,minsum,1,maxnum,dpupper,mod) - helper(0,minsum,1,minnum,dplower,mod))%mod;
        return ((upper - lower)%mod + mod)%mod;
    }
};