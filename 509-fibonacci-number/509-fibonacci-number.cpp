class Solution {
public:
    int fib(int n) {
       /*purely recursive,recursive dp possible with memoization
        if(n<=1)
           return n;
        return fib(n-1)+fib(n-2);
        */
        if(n<=1)
            return n;
        int t0=0,t1=1;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=t0+t1;
            t0=t1;
            t1=ans;
        }
        return ans;
    }
};