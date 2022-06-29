class Solution {
public:
    int mySqrt(int x) {
        long long low=0, high=x;
        long long ans;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid>x) high=mid-1;
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};