class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            sum+=x;
            if(mp.count(sum%k)>0)
            {
                if((i-mp[sum%k])>1)
                    return true;     
            }
            else mp[sum%k] = i; 
        }
        return false;
    }
};