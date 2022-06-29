class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(), people.end());
        vector<vector<int>> ans(n, vector<int> (2,-1));
        for(int i=0;i<n;i++)
        {
            int h = people[i][0];
            int req=people[i][1];
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(cnt==req && ans[j][0]==-1)
                {
                    ans[j]=people[i];
                    // cout<<j<<" "<<ans[j][0]<<endl;
                    // break;
                }
                if(ans[j][0]>=h || ans[j][0]==-1) cnt++;
            }
        }
        return ans;
    }
};