class Solution {
private:
    int merge(int low, int mid, int high, vector<int>& nums)
    {
        vector<int> temp;
        int left=low, right=mid+1, ans=0;
        while(left<=mid)
        {
            while(right<=high && 2LL *nums[right]<nums[left]) right++;
            ans+=right-(mid+1);
            left++;
        }
        left=low; right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);
        int i=0;
        for(int j=low;j<=high;j++)
        {
            nums[j]=temp[i++];
        }
        return ans;
    }
    int mergesort(int low, int high, vector<int>& nums)
    {
        if(low==high) return 0;
        int ans=0, mid=low + (high-low)/2;
        ans+=mergesort(low,mid,nums);
        ans+=mergesort(mid+1,high,nums);
        ans+=merge(low,mid,high,nums);
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(0,n-1,nums);
    }
};