class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        // sort(citations.begin(), citations.end());
        // int n=citations.size();
        // int low=1, high=n;
        // int ans=0;
        // while(low<=high)
        // {
        //     int mid = low+(high-low)/2;
        //     if(citations[n-mid]>=mid)
        //     {
        //         ans=mid;
        //         low=mid+1;
        //     }
        //     else
        //     {
        //         high=mid-1;
        //     }
        // }
        // return ans;
        
        int n=citations.size();
        vector<int> count(n+1);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(citations[i]>n) sum++;
            else 
            {
                count[citations[i]]++;
            }
        }
        for(int i=n;i>=0;i--)
        {
            sum+=count[i];
            if(sum>=i) return i;
        }
        return 0;
    }
};