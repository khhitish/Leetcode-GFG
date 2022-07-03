class Solution {
public:
    double myPow(double x, int n) {
        // if(n==0) return 1;
        // if(n<0)
        // {
        //     x=(1/x);
        //     n=abs(n);
        // }
        // double res=1;
        // if(n%2==1)
        // {
        //     res*=x;
        // }
        // double temp=myPow(x,n/2);
        // return res*temp*temp;
        
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        double res=1;
        while(n>0)
        {
            if(n%2==1)
            {
                res*=x;
            }
            x=(x*x);
            n/=2;
        }
        return res;
    }
};