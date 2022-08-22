class Solution {
public:
    bool isPowerOfFour(int t) {
        long long n = t;
        if((n&(n-1))==0)
        {
            for(int i=0;i<31;i++)
            {
                if(((n>>i) & 1) == 1)
                {
                    if(i%2==0) return true;
                    else return false;
                }
            }
        }
        return false;
    }
};