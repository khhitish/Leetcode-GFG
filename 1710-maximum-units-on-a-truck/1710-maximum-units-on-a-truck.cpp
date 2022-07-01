class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]>v2[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans=0;
        for(auto&x : boxTypes)
        {
            int number = min(truckSize,x[0]);
            ans +=(number * x[1]);
            truckSize-=number;
            if(truckSize==0) return ans;
        }
        return ans;
    }
};