class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        int ans = 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            long long sum = 1LL*n*mid;
            long long subleft, subright;
            if(index < mid) {
                subleft = 1LL*index*(index + 1)/2;
            }
            else {
                subleft = 1LL*(mid-1)*mid/2 + 1LL*(mid-1)*(index-(mid-1));
            }
            if((n - index - 1) < mid) {
                subright = 1LL*(n - index - 1)*((n - index - 1) + 1)/2;
            }
            else {
                subright = 1LL*(mid-1)*mid/2 + 1LL*(mid-1)*((n - index - 1)-(mid-1));
            }
            // cout<<mid<<" "<<sum<<" "<<subleft<<" "<<subright<<endl;
            if(sum - subright - subleft <=maxSum) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};