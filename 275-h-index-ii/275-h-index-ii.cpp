class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=1, high=n;
        int ans=0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(citations[n-mid]>=mid)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};