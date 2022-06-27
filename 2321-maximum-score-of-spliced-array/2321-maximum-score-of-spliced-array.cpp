class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int extra = 0, maxextra = INT_MIN;
        for(int i=0;i<nums1.size();i++)
        {
            extra += nums2[i]-nums1[i];
            maxextra=max(extra,maxextra);
            if(extra<0) extra =0;
        }
        int ans1;
        if(maxextra<0) ans1=sum1;
        else ans1 = sum1 + maxextra;
        extra = 0; maxextra = INT_MIN;
        for(int i=0;i<nums1.size();i++)
        {
            extra += nums1[i]-nums2[i];
            //cout<<extra<<" ";
            maxextra=max(extra,maxextra);
            //cout<<maxextra<<" ";
            if(extra<0) extra =0;
        }
        int ans2;
        if(maxextra<0) ans2=sum1;
        else ans2 = sum2 + maxextra;
        //cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
    }
};