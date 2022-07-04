class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int temp=n, ans=n, times=0;
        int prev=9,index=0,carry=0;
        while(temp>0)
        {
            int curr=temp%10;
            if(curr>prev)
            {
                times=index;
                ans=temp;
                prev=curr-1;
            }
            else prev=curr;
            temp/=10;
            index++;
        }
        if(times==0) return ans;
        ans--;
        while(times--)
        {
            ans=ans*10 + 9;
        }
        return ans;
    }
};