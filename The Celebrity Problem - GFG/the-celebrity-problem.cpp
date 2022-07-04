// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // stack<int> s;
        // for(int i=0;i<n;i++) s.push(i);
        // while(s.size()>1)
        // {
        //     int x=s.top(); s.pop();
        //     int y=s.top(); s.pop();
        //     if(M[x][y]==1) 
        //     {
        //         s.push(y);
        //     }
        //     else
        //     {
        //         s.push(x);
        //     }
        // }
        // int celeb=s.top();
        // for(int i=0;i<n;i++)
        // {
        //     if(i==celeb) continue;
        //     if(M[i][celeb]==0 || M[celeb][i]==1) return -1;
        // }
        // return celeb;
        
        //constant space two pointers
        int i=0, j=n-1;
        while(i<j)
        {
            if(M[i][j]==0) j--;
            else i++;
        }
        int celeb=i;
        for(int k=0;k<n;k++)
        {
            if(k==celeb) continue;
            if(M[k][celeb]==0 || M[celeb][k]==1) return -1;
        }
        return celeb;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends