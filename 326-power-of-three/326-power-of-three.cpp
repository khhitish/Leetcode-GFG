class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        else 
        {
            if(n==1)
                return true;//base condition for recursion
            else 
            {
                if(n%3!=0)
                    return false;//another base condition
                else
                    return isPowerOfThree(n/3);
            }
        }
    }
};