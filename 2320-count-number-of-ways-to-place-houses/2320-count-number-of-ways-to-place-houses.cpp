class Solution {
public:
    int countHousePlacements(int n) {
        int m = n+2;
        long long prev2=0, prev1=1;
        for(int i=2;i<=m;i++)
        {
            long long temp = (prev1+prev2)%1000000007;
            prev2=prev1;
            prev1=temp;
        }
        return (prev1*prev1)%1000000007;
    }
};