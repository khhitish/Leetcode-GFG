// class Solution {
// private:
//     int word_ladder_1(string start, string end, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         if(dict.count(end)==0) return 0;
//         if(start==end) return 1;
//         unordered_set<string> visited;
//         queue<string> q;
//         q.push(start);
//         int count_words=1;
//         while(!q.empty())
//         {
//             int n = q.size();
//             while(n--)
//             {
//                 string curr = q.front();
//                 q.pop();
//                 if(curr == end) return count_words;
//                 for(int i = 0;i<curr.size();i++)
//                 {
//                     char x = curr[i];
//                     for(char c = 'a';c<='z';c++)
//                     {
//                         string temp = curr.substr(0,i) + c + curr.substr(i+1);
//                         if(dict.count(temp)!=0)
//                         {
//                             q.push(temp);
//                             dict.erase(temp);
//                         }
//                     }
//                 }
//             }
//             count_words++;
//         }
//         return 0;
//     }
    
//     void helper(string word, string& end, unordered_set<string>& dict, 
//                 vector<vector<string>>& ans, vector<string>& curr, int currlevel,int maxl)
//     {
//         if(currlevel==maxl)
//         {
//             if(word==end) ans.push_back(curr);
//             return;
//         }
//         for(int i=0;i<word.size();i++)
//         {
//             char c = word[i];
//             for(char x = 'a';x<='z';x++)
//             {
//                 if(x==c) continue;
//                 string temp = word.substr(0,i) + x + word.substr(i+1);
//                 if(dict.count(temp)!=0)
//                 {
//                     dict.erase(temp);
//                     curr.push_back(temp);
//                     helper(temp,end,dict,ans,curr,currlevel+1,maxl);
//                     curr.pop_back();
//                     dict.insert(temp);
//                 }
//             }
//         }
//     }
// public:
//     vector<vector<string>> findLadders(string start, string end, vector<string>& wlist) {
//         // // TLE Saving paths in the queue and performing bfs
//         // unordered_set<string> dict(wlist.begin(), wlist.end());
//         // vector<vector<string>> ans;
//         // if(dict.count(end)==0) return ans;
//         // queue<vector<string>> q;
//         // q.push({start});
//         // bool found = false;
//         // int level=0;
//         // while(!q.empty())
//         // {
//         //     int n = q.size();
//         //     unordered_set<string> visited;
//         //     while(n--)
//         //     {
//         //         auto curr_path = q.front();
//         //         q.pop();
//         //         string curr_word = curr_path.back();
//         //         for(int i=0;i<curr_word.size();i++)
//         //         {
//         //             char c=curr_word[i];
//         //             for(char x='a';x<='z';x++)
//         //             {
//         //                 if(c==x) continue;
//         //                 string temp = curr_word.substr(0,i) + x + 
//         //                     curr_word.substr(i+1);
//         //                 if(dict.count(temp)!=0)
//         //                 {
//         //                     visited.insert(temp);
//         //                     curr_path.emplace_back(temp);
//         //                     q.push(curr_path);
//         //                     curr_path.pop_back();
//         //                     if(temp==end) found=true;
//         //                 }
//         //             }
//         //         }
//         //     }
//         //     //cout<<level++<<endl;
//         //     if(found==true)
//         //     {
//         //         break;
//         //     }
//         //     for(auto&x : visited)
//         //     {
//         //         dict.erase(x);
//         //     }
//         //     // visited.clear();
//         // }
//         // while(!q.empty())
//         // {
//         //     if(q.front().back()==end)
//         //     {
//         //         ans.emplace_back(q.front());
//         //     }
//         //     q.pop();
//         // }
//         // return ans;
        
//         vector<vector<string>> ans;
//         vector<string> curr;
//         curr.push_back(start);
//         int maxlen = word_ladder_1(start, end, wlist);
//         cout<<maxlen<<endl;
//         unordered_set<string> dict(wlist.begin(), wlist.end());
//         helper(start,end,dict,ans,curr,1,maxlen);
//         return ans;
        
//     }
// };







// from discuss: https://leetcode.com/problems/word-ladder-ii/discuss/2423868/C++-oror-BFS-and-BackTracking-oror-Faster-oror-30ms
class Solution {
public:
  unordered_set<string> dic;
  unordered_map<string,int> mp;
  vector<vector<string>> ans;
    void dfs(string ew,vector<string> &temp,string bw)
    {
        
        int curr=mp[ew];
         temp.push_back(ew);
        if(ew==bw)
        {
            reverse(temp.begin(),temp.end());
           ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return ;
        }
        for(int i=0;i<ew.size();i++)
        {
            string st=ew;
          for(char ch='a';ch<='z';ch++)
          {
           st[i]=ch;
              if(mp[st] and mp[st]==curr-1)
              { 
                  dfs(st,temp,bw);
              }
         }
        }
        temp.pop_back();
        
    }
    
   
 
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
     
      
        for(auto it:wl)dic.insert(it);
        queue<string> q;
        q.push(bw);
        mp[bw]++;
            while(!q.empty())
            {
                auto k=q.front();
                q.pop();
                int steps=mp[k]+1;
                for(int i=0;i<k.size();i++)
                {
                    string temp=k;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(dic.count(temp) and !mp[temp])
                        {
                            mp[temp]=steps;
                            q.push(temp);
                        }
                    }
                }   
            }
        if(mp[ew])
        {
            vector<string> temp;
            dfs(ew,temp,bw);        }
        return ans;
        
    }
};