class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto&x : s)
        {
            freq[x-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int prev=freq[0], ans=0;
        for(int i=1;i<26;i++)
        {
            if(freq[i]>=prev && freq[i]!=0)
            {
                ans+=prev==0? freq[i]-prev : freq[i]-prev+1;
                freq[i]=prev==0?prev:prev-1;
            }
            prev=freq[i];
        }
        return ans;
    }
};