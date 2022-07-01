class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long long hours=0;
            for(auto&x : piles)
            {
                if(x%mid==0) hours+=(x/mid);
                else hours+=(x/mid) + 1;
            }
            if(hours>h)
            {
               low=mid+1; 
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};