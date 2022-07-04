// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int temp=b, bsetbits=0;
        while(temp>0)
        {
            temp=(temp & (temp-1));
            bsetbits++;
        }
        int asetbits=0;
        temp=a;
        while(temp>0)
        {
            temp=(temp & (temp-1));
            asetbits++;
        }
        if(asetbits==bsetbits) return a;
        else if(bsetbits>asetbits)
        {
            int x=a;
            int req=bsetbits-asetbits;
            for(int i=0;i<31 && req>0;i++)
            {
                if((x & (1<<i))==0)
                {
                    x|=(1<<i);
                    req--;
                }
            }
            return x;
        }
        else
        {
            int x=a;
            int req=asetbits-bsetbits;
            for(int i=0;i<31 && req>0;i++)
            {
                if((x & (1<<i))!=0)
                {
                    x^=(1<<i);
                    req--;
                }
            }
            return x;
        }
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends