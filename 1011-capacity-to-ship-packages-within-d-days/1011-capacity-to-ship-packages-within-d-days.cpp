class Solution {
private:
    bool ispossibleans(int cap, vector<int>& weights, int days)
    {
        int curr=0, reqdays=1;
        for(auto&x : weights)
        {
            curr+=x;
            if(curr>cap)
            {
                curr=x;
                reqdays++;
            }
            if(reqdays>days) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN, high=0;
        for(auto&x : weights)
        {
            low=max(low,x);
            high+=x;
        }
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(ispossibleans(mid,weights,days))
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