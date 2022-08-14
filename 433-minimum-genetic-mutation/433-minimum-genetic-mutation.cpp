class Solution {
public:
    // can also be done in one set, if we delete the word from our dictionary before pushing it into queue (instead of adding it into a new visited set)
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        unordered_set<string> visited;
        if(dict.count(end)==0) return -1;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        vector<char> chars = {'A', 'C', 'G', 'T'};
        int level=0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                q.pop();
                //cout<<curr<<endl;
                if(curr == end)
                {
                    return level;
                }
                for(int i=0;i<curr.size();i++)
                {
                    char c = curr[i];
                    for(auto &x : chars)
                    {
                        if(x == c) continue;
                        string temp = curr.substr(0,i) + x + curr.substr(i+1);
                        if(dict.count(temp)!=0 && visited.count(temp)==0)
                        {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};