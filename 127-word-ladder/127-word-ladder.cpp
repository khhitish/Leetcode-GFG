class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.count(end)==0) return 0;
        if(start==end) return 1;
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int count_words=1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                q.pop();
                if(curr == end) return count_words;
                for(int i = 0;i<curr.size();i++)
                {
                    char x = curr[i];
                    for(char c = 'a';c<='z';c++)
                    {
                        string temp = curr.substr(0,i) + c + curr.substr(i+1);
                        if(dict.count(temp)!=0 && visited.count(temp)==0)
                        {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            count_words++;
        }
        return 0;
    }
};