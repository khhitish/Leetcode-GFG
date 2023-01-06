//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int num1,int num2)
    {   
        vector<bool> sieve(1e4,true);
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2; i*i<=1e4;i++)
        {
            if(sieve[i] == false) continue;
            for(int j=i*i;j<1e4;j+=i)
            {
                sieve[j] = false;
            }
        }
        queue<int> q;
        vector<int> vis(1e4,0);
        q.push(num1);
        vis[num1]=1;
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int num = q.front();
                q.pop();
                if(num == num2) return level;
                string curr = to_string(num);
                for(int i=0;i<4;i++)
                {
                    string temp = curr;
                    for(int j=0;j<=9;j++)
                    {
                        temp[i] = ('0' + j);
                        int newnum = stoi(temp);
                        if(newnum>=1000 && newnum<=9999 && vis[newnum]==0 && sieve[newnum] == true)
                        {
                            q.push(newnum);
                            // cout<<newnum<<" ";
                            vis[newnum] = 1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends