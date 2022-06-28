class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> m;
        for(auto&x : nums)
        {
            m[x]++;
        }
        int ans=0;
        for(auto &it: m)
        {
            if(it.second>1)
            {
                m[it.first+1]+=it.second-1;
                ans+=it.second-1;
                it.second=1;
            }
        }
        return ans;
    }
};