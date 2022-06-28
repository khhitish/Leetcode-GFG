class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto&x : s)
        {
            freq[x-'a']++;
        }
        map<int,int> mpp;
        for(auto&x : freq)
        {
            if(x>0) mpp[x]++;
        }
        int ans = 0;
        for(auto it=mpp.rbegin(); it!=mpp.rend(); it++)
        {
            if(it->first==0) break;
            if(it->second>1)
            {
                ans+=it->second-1;
                //cout<<ans<<" ";
                mpp[it->first-1]+=it->second-1;
            }
        }
        return ans;
    }
};