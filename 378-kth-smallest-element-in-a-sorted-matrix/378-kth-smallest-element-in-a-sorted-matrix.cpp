class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            int count=0;
            // for(int i=0;i<n;i++)
            // {
            //     count += lower_bound(matrix[i].begin(), matrix[i].end(),mid) - matrix[i].begin();
            // }
            // O(2n) counting like search in 2d matrix 2
            int r = 0, c=n-1;
            while(r<n && c>=0)
            {
                while(c>=0 && matrix[r][c] >= mid) c--;
                count+=(c+1);
                //if(mid==12)cout<<c<<endl;
                r++;
            }
            if(count<k)
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high =  mid-1;
            }
        }
        return ans;
    }
};