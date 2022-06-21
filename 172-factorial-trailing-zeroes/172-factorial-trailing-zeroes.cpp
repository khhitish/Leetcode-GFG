class Solution {
public:
    int trailingZeroes(int n) {
        
        // time: O(nlog5(n))
        // int n5=0;
        // for(int i=1;i<=n;i++)
        // {
        //     int t=i;
        //     while(t%5==0)
        //     {
        //         n5++;
        //         t/=5;
        //     }
        // }
        // return n5;
        
        // time= O(log5(n))
        
        int ans=0;
        int i=5;
        while(i<=n)
        {
            ans+=(n/i);
            i*=5;
        }
        return ans;
    }
};