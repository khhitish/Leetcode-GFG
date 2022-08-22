class Solution {
public:
    bool isPowerOfFour(int t) {
        // long long n = t;
        // if((n&(n-1))==0)
        // {
        //     for(int i=0;i<31;i++)
        //     {
        //         if(((n>>i) & 1) == 1)
        //         {
        //             if(i%2==0) return true;
        //             else return false;
        //         }
        //     }
        // }
        // return false;
        if(t<=0) return false;
        
        
        if(t==1) return true;
        else if(t%4!=0) return false;
        else return isPowerOfFour(t/4);
    }
};