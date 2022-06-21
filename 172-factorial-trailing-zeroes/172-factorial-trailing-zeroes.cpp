class Solution {
    // https://youtu.be/zUuLh6x1i6M
    // https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC++-Solution-(with-detailed-explaination)
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
        // we need to check number of 5s in all numbers starting from 1 to n. prev approach did this in nlogn time, this one does the same in logn time
        //we know that we encounter a number divisible by 5 every 5 steps, so if we divide n by 5 we will get number of numbers from 1 to n divisible by 5, but then 25 has 2 fives, wo we account 1 5 by taking n/5 and another 5 of 25 by taking n/25. 125 has 3 5s 2 are taken care of by 5 and 25 another one by 125, similarly we keep doing this as lo g as denominator is less than equal to n, i.e. we do this for log5(n) times
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