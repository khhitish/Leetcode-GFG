class Solution
{
    public:
        int kthFactor(int n, int k)
        {
            int i = 1;
            while (i * i <= n)
            {
                if (n % i == 0)
                {
                    k--;
                    if (k == 0) return i;
                }
                //cout<<i<<endl;
                i++;
            }
            i--;
            while (i >= 1)
            {
                if (i *i == n)
                {
                    i--;
                    continue;
                }
                if (n % i == 0)
                {
                    k--;
                    if (k == 0) return n / i;
                }
                //out<<i<<endl;
                i--;
            }
            return -1;
        }
};