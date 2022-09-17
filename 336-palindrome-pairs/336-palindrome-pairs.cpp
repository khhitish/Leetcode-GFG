class Solution {
private:
    bool isPalin(string& s)
    {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mpp;
        for(int i=0;i<words.size();i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mpp[temp]=i;
        }
        vector<vector<int>> ans;
        
        if(mpp.count("")!=0)
        {
            for(int i=0;i<words.size();i++)
            {
                if(words[i]=="")continue;
                if(isPalin(words[i]))ans.push_back({i,mpp[""]});
            }
        }
        
        for(int i=0;i<words.size();i++)
        {
            string left = "";
            string right = words[i];
            
            
            for(int j=0;j<words[i].size();j++)
            {
                left.push_back(words[i][j]);
                right.erase(0,1);
                
                if(isPalin(left) && mpp.count(right)!=0 && mpp[right]!=i)
                {
                    ans.push_back({mpp[right],i});
                }
                
                if(isPalin(right) && mpp.count(left)!=0 && mpp[left]!=i)
                {
                    ans.push_back({i,mpp[left]});
                }
            }
        }
        return ans;
    }
};