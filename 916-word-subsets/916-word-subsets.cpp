class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bhash(26,0);
        for(auto&x : words2)
        {
            vector<int> temphash(26,0);
            for(auto&c : x)
            {
                temphash[c - 'a']++;
            }
            for(int i=0;i<26;i++)
            {
                bhash[i] = max(bhash[i], temphash[i]);
            }
        }
        vector<string> ans;
        for(auto&x : words1)
        {
            vector<int> ahash(26,0);
            for(auto&c : x)
            {
                ahash[c - 'a']++;
            }
            bool isuni = true;
            for(int i=0;i<26;i++)
            {
                if(ahash[i]<bhash[i])
                {
                    isuni = false;
                    break;
                }
            }
            if(isuni)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};