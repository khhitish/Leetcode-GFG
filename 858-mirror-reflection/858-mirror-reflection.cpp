// https://leetcode.com/problems/mirror-reflection/discuss/146336/Java-solution-with-an-easy-to-understand-explanation
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = p, n = q;
        // m*q = n*p
        while(m%2 == 0 && n%2==0)
        {
            m/=2;
            n/=2;
        }
        if(m%2 == 0) return 2;
        else
        {
            if(n%2==0) return 0;
            else return 1;
        }
    }
};