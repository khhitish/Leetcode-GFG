// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  private:
  int pref(char x)
  {
      if(x=='(') return 0;
      else if(x=='+' || x=='-') return 1;
      else if(x=='*' || x=='/') return 2;
      else return 3;
  }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans;
        stack<char> st;
        for(auto&x : s)
        {
            if((x<='9' && x>='0') || (x<='z' && x>='a') || (x<='Z' && x>='A')) ans+=x;
            else
            {
                if(x=='(') st.push(x);
                else if(x==')')
                {
                    while(st.top()!='(')
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while(!st.empty() && pref(x)<=pref(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(x);
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends