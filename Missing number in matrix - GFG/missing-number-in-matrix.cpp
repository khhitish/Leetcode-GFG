//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


typedef long long ll;
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& mat) {
        int n = mat.size();
        int row,col;
        vector<ll> rowsum(n), colsum(n);
        ll diapri=0, diasec=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    row=i;
                    col=j;
                }
                colsum[j]+=mat[i][j];
                rowsum[i]+=mat[i][j];
                if(i-j == 0)
                {
                    diapri+=mat[i][j];
                }
                if(i+j == n-1)
                {
                    diasec+=mat[i][j];
                }
            }
        }
        ll temp = rowsum[row];
        if(temp!=colsum[col])
        {
            return -1;
        }
        if(row==col && diapri!=temp)
        {
            return -1;
        }
        if(row+col == n-1 && diasec!=temp)
        {
            return -1;
        }
        unordered_set<int> st;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=row)
            {
                st.insert(rowsum[i]);
                if(rowsum[i]<=temp)
                {
                    return -1;
                }
                ans = rowsum[i] - temp;
            }
            if(i!=col)
            {
                st.insert(colsum[i]);
                if(colsum[i]<=temp)
                {
                    return -1;
                }
            }
            if(st.size() > 1)
            {
                return -1;
            }
        }
        if(row!=col)
        {
            st.insert(diapri);
            if(diapri <= temp)
            {
                return -1;
            }
            if(st.size() > 1)
            {
                return -1;
            }
        }
        if(row+col == n-1 && diasec!=temp)
        {
            st.insert(diasec);
            if(diasec <= temp)
            {
                return -1;
            }
            if(st.size() > 1)
            {
                return -1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends