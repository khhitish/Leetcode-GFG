class Solution {
private:
    void helper(int num, int n, int k, vector<int>& ans)
    {
        
        if(n==0)
        {
            ans.push_back(num);
            return;
        }
        int last = num%10;
        if((last+k)/10==0)
        {
            num = num*10 + (last+k);
            helper(num,n-1,k,ans);
            num/=10;
        }
        if((last-k)>=0 && last-k!=last+k)
        {
            num = num*10 + (last-k);
            helper(num,n-1,k,ans);
            num/=10;
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            helper(i,n-1,k,ans);
        }
        return ans;
    }
};