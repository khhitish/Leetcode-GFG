class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mini = arr.front(), maxi = arr.front();
        for(auto&x : arr) {
            maxi = max(maxi,x);
            mini = min(mini,x);
        }
        if(maxi == mini) return true;
        int n = arr.size();
        if((maxi - mini)%(n-1)!=0) return false;
        int d = (maxi - mini)/(n-1);
        int i = 0;
        while(i<n) {
            if(((arr[i] - mini) % d) != 0)return false;
            else if(((arr[i] - mini)/d)==i)i++;
            else {
                int pos = (arr[i] - mini) / d;
                if (arr[pos] == arr[i]) return false;
                swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};