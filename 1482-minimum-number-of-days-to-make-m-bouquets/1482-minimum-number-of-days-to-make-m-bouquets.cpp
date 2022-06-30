class Solution {
private:
    bool ispossibleans(int mid, vector<int>& bd, int m, int k)
    {
        int n=bd.size(), i=0;
        int count=0;
        while(i<n)
        {
            int j=i;
            while(j<n && bd[j]<=mid && j-i<k)
            {
                j++;
            }
            if(j-i==k)
            {
                count++;
                i=j;
            }
            else
            {
                i=j+1;
            }
            if(count>=m) return true;
        }
        return false;
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