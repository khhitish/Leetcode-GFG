class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int lim = (m+n)/2;
        int low=lim-n<0? 0 : lim-n,high=min(lim,m);
        bool iseven = (m+n)%2==0 ? true : false;
        //cout<<iseven<<endl;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            // if(mid>m)
            // {
            //     high=mid-1;
            //     continue;
            // }
            // else if(lim-mid > n)
            // {
            //     low=mid+1;
            //     continue;
            // }
            int l1,l2,r1,r2;
            l1 = mid==0? INT_MIN : nums1[mid-1];
            l2 = lim-mid==0 ? INT_MIN : nums2[lim-mid-1];
            r1 = mid==m? INT_MAX : nums1[mid];
            r2 = lim-mid==n? INT_MAX : nums2[lim-mid];
            //cout<<mid<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" ";
            //cout<<endl;
            if(l1>r2)
            {
                high=mid-1;
            }
            else if(l2>r1)
            {
                low=mid+1;
            }
            else
            {
                if(iseven)
                {
                    double median = (max(l1,l2) + min(r1,r2))/2.0;
                    return median;
                }
                else
                {
                    return min(r1,r2);
                }
            }
        }
        
        return -1;
    }
};