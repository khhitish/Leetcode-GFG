class Solution {
vector<int> count(int n)
{
    vector<int> v(10,0);
    while(n>0)
    {
        v[n%10]++;
        n/=10;
    }
    return v;
}
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v = count(n);
        
        for(int i=1;i<=1e9;i=(i<<1))
        {
            //cout<<i<<" ";
            if(count(i) == v) return true;
        }
        return false;
    }
};