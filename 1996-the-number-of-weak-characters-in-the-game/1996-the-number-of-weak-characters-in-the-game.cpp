class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        // for(auto&x : p)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        // cout<<endl;
        int i = n-1, ans=0;
        int attack=INT_MIN, defense=INT_MIN;
        while(i>=0)
        {
            int newdef=INT_MIN;
            int temp=p[i][0];
            while(i>=0 && p[i][0] == temp)
            {
                newdef=max(newdef,p[i][1]);
                if(defense > p[i][1] && attack>p[i][0])
                {
                    ans++;
                    // cout<<defense<<" "<<p[i][0] <<" "<<p[i][1]<<endl;
                }
                i--;
            }
            defense =max(newdef,defense);
            attack=p[i+1][0];
        }
        return ans;
        
    }
};