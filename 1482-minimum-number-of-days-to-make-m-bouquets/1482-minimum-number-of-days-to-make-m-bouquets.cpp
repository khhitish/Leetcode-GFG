class Solution {
private:
    bool ispossibleans(int mid, vector<int>& bd, int m, int k)
    {
        int bouq=0, len=0;
        for(auto&x : bd)
        {
            if(x<=mid)
            {
                len++;
            }
            else
            {
                bouq+=(len/k);
                len=0;
            }
            // if(len==k)
            // {
            //     bouq++;
            //     len=0;
            // }
        }
        bouq+=(len/k);
        return bouq>=m;
    }
public:
    int minDays(vector<int>& bd, int m, int k) {
        if(m*k > bd.size()) return -1;
        int low=1, high=*max_element(bd.begin(), bd.end());
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(ispossibleans(mid,bd,m,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};