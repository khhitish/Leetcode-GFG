class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high=target, ans=-1;
        int mindiff = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int sum=0;
            bool flag=false;
            for(auto&x : arr)
            {
                if(x<=mid) sum+=x;
                else
                {
                    flag=true;
                    sum+=mid;
                }
            }
            if(mindiff> abs(sum-target))
            {
                ans=mid;
                mindiff=abs(sum-target);
            }
            else if(mindiff==abs(target-sum))
            {
                ans=min(ans,mid);
            }
            if(sum>=target)
            {
                high=mid-1;
            }
            else
            {
                if(flag==true) low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};