class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        bool iseven = false;
        if((m+n) % 2 == 0) iseven = true;
        int req = (m+n)/2;
        int low = req<=n ? 0 : req-n;
        int high = min(m,req);
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            //mid represents the number of elements to be taken from arr1 into left half, req-mid represents the number of elements to be taken from arr2 into left half
            int l1, l2, r1, r2;
            l1 = mid==0 ? INT_MIN : nums1[mid-1]; // no elements picked from arr1 into left half or not
            l2 = req-mid==0 ? INT_MIN : nums2[req - mid - 1]; // no elements picked from arr2 into left half or not
            r1 = mid==m ? INT_MAX : nums1[mid]; //all elements of arr1 went into left half or not
            r2 = req-mid==n ? INT_MAX : nums2[req - mid]; //all elements of arr2 went into left half or not
            if(l1 > r2)
            {
                high = mid-1;
            }
            else if(l2 > r1)
            {
                low = mid+1;
            }
            else
            {
                if(iseven)
                {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                else return min(r1,r2);
            }
        }
        return -1;
    }
};