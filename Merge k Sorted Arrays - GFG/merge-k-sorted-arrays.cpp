// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
class Node
{
    public:
    int i;
    int j;
    int val;
    
    Node(int valu, int x, int y)
    {
        val=valu;
        i=x;
        j=y;
    }
};
struct comp {
    bool operator()(Node const& p1, Node const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.val > p2.val;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<Node,vector<Node>, comp> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i][0],i,0});
        }
        vector<int> ans;
        while(!pq.empty())
        {
            auto temp=pq.top();
            int i=temp.i;
            int j=temp.j;
            int val=temp.val;
            pq.pop();
            if(j+1<k)
            {
                pq.push({arr[i][j+1],i,j+1});
            }
            ans.push_back(val);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends