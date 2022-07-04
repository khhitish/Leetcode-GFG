class Solution {
private:
    int largestrectangle(vector<int>& h) {
        stack<int> s;
        int ans=0, n=h.size();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && h[s.top()]>=h[i])
            {
                int j=s.top();s.pop();
                int k = s.empty() ? -1 : s.top();
                int temp = h[j]*(i-k-1);
                ans=max(ans,temp);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int j=s.top();s.pop();
            int k = s.empty() ? -1 : s.top();
            int temp = h[j]*(n-k-1);
            ans=max(ans,temp);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n =matrix[0].size();
        vector<int> v(n,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1') v[j]++;
                else v[j]=0;
            }
            int temp = largestrectangle(v);
            ans=max(ans,temp);
        }
        return ans;
        
    }
};