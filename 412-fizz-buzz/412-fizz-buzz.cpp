class Solution
{
    public:
        vector<string> fizzBuzz(int n)
        {
            vector<string> v(n);
            for(int i=1;i<=n;i++) v[i-1]=to_string(i);
            for(int i=3;i<=n;i+=3)v[i-1] = "Fizz";
            for(int i=5;i<=n;i+=5)v[i-1] = "Buzz";
            for(int i=15;i<=n;i+=15)v[i-1]="FizzBuzz";
            return v;
        }
};