class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        // // brute force
        // int n = grid.size();
        // int ans = 0;
        // for(int i=0;i<n;i++) {
        //     int rowstart = grid[i][0];
        //     for(int j=0;j<n;j++) {
        //         if(grid[0][j] == rowstart) {
        //             bool flag = true;
        //             for(int k=0;k<n;k++) {
        //                 if(grid[i][k] != grid[k][j]) {
        //                     flag = false;
        //                     break;
        //                 }
        //             }
        //             if(flag)ans++;
        //         }
        //     }
        // }
        // return ans;

        // map method
        int n = grid.size();
        int ans = 0;
        map<vector<int>, int> mp;
        for(int i=0;i<n;i++) {
            mp[grid[i]]++;
        }
        for(int j=0;j<n;j++) {
            vector<int> col(n);
            for(int i=0;i<n;i++) {
                col[i] = grid[i][j];
            }
            if(mp.count(col)) {
                ans+=mp[col];
            }
        }
        return ans;

    }
};