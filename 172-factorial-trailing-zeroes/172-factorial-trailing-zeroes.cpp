class Solution {
public:
    int trailingZeroes(int n) {
        int n5=0;
        for(int i=1;i<=n;i++)
        {
            int t=i;
            while(t%5==0)
            {
                n5++;
                t/=5;
            }
        }
        return n5;
    }
};