class Solution
{
    public:
        int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
        {
            sort(hc.begin(), hc.end());
            sort(vc.begin(), vc.end());
            long long maxh = hc[0], maxv = vc[0];
            for (int i = 1; i < hc.size(); i++)
            {
                maxh = max(maxh, (long long)(hc[i] - hc[i - 1]));
            }
            maxh = max(maxh, (long long)(h - hc.back()));
            for (int i = 1; i < vc.size(); i++)
            {
                maxv = max(maxv, (long long)(vc[i] - vc[i - 1]));
            }
            maxv = max(maxv, (long long)(w - vc.back()));
            int mod = 1e9 + 7;
            return ((maxv % mod) * (maxh % mod)) % mod;
        }
};