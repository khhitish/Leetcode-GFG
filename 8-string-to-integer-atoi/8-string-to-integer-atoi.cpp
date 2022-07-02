class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size(), ans=0;
        
        while(i<n && s[i]==' ') i++;
        if(i==n) return ans;
        
        bool isnegative=false;
        if(s[i]=='-')
        {
            isnegative=true;
            i++;
        }
        else if(s[i]=='+')
        {
            isnegative=false;
            i++;
        }
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            int digit = s[i]-'0';
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX%10))
            {
                return isnegative==true? INT_MIN : INT_MAX;
            }
            ans=ans*10 + digit;
            i++;
        }
        if(isnegative==true) return -1 * ans;
        else return ans;
    }
};