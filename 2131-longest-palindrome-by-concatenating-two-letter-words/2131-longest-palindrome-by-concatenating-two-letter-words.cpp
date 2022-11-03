class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(auto &x: words)
        {
            m[x]++;
        }
        int ans=0;
        bool done=false;
        for(auto &x: words)
        {
            if(m.find(x)!=m.end())
            {
                if(x[0]==x[1])
                {
                    if(m[x]%2==0)
                    {
                        ans+=2*m[x];
                        m[x]=0;
                    }
                    else
                    {
                        if(done==false)
                        {
                            ans+=2*m[x];
                            m[x]=0;
                            done=true;
                        }
                        else
                        {
                            int t1=m[x]/2;
                            ans+=4*t1;
                            m[x]=0;
                        }
                    }
                }
                else
                {
                    string temp="";
                    temp+=x[1];
                    temp+=x[0];
                    if(m.find(temp)!=m.end())
                    {
                        int t=min(m[x],m[temp]);
                        ans+=4*t;
                        m[x]=0;
                        m[temp]=0;
                    }
                    else
                    {
                        m[x]=0;
                    }
                }
            }

        }
        return ans;
        
    }
};