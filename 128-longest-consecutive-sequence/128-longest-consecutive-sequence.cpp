class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        for(auto&x : nums)st.insert(x);
        int ans=1;
        for(auto&x : nums)
        {
            if(st.count(x)==0) continue;
            st.erase(x);
            int tempans=1;
            int prev = x-1, next = x+1;
            while(st.count(prev)>0)
            {
                st.erase(prev);
                prev--;
                tempans++;
            }
            while(st.count(next)>0)
            {
                st.erase(next);
                next++;
                tempans++;
            }
            ans=max(ans,tempans);
        }
        return ans;
    }
};