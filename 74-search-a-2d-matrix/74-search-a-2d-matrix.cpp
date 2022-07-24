class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // binary search as 1d array
        // int low = 0, high = m*n -1;
        // while(low<=high)
        // {
        //     int mid = low + (high-low)/2;
        //     int val = matrix[mid/n][mid%n];
        //     if(val==target) return true;
        //     else if(val>target) high=mid-1;
        //     else low=mid+1;
        // }
        // return false;
        
        int rowans=-1;
        int low = 0, high = m-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int val = matrix[mid][0];
            if(target==val) return true;
            else if(target > val)
            {
                rowans = mid;
                low = mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(rowans==-1) return false;
        low = 0, high=n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int val = matrix[rowans][mid];
            if(val==target) return true;
            else if(val >  target) high=mid-1;
            else low = mid+1;
        }
        return false;
    }
};