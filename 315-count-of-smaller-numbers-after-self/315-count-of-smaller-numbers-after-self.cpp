class Solution {
private:
    void merge(int low, int mid, int high, vector<pair<int,int>>& nums, vector<int>& ans)
    {
        vector<pair<int,int>> temp;
        int left = low, right = mid+1;
        while(left<=mid)
        {
            while(right<=high && nums[right].first < nums[left].first) right++;
            int ind = nums[left].second;
            ans[ind]+=right - (mid+1);
            left++;
        }
        left=low, right = mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left].first < nums[right].first)
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
        for(int j = low;j<=high;j++)
        {
            nums[j]=temp[i++];
        }
        
    }
    
    void mergesort(int low, int high, vector<pair<int,int>>& nums, vector<int>& ans)
    {
        if(low==high) return;
        int mid = low + (high-low)/2;
        mergesort(low,mid,nums,ans);
        mergesort(mid+1,high,nums,ans);
        merge(low,mid,high,nums,ans);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergesort(0,n-1,v,ans);
        return ans;
    }
};