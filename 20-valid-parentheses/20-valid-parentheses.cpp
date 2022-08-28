// class Solution {
// public:
//     bool isValid(string given) {
//         stack<char> s;
//         for(auto &x:given)
//         {
//             if(x=='(' || x=='{' || x=='[')
//             {
//                 s.push(x);
//             }
//             else
//             {
//                 if(s.empty()==true) return false;
//                 if(x==')' && s.top()=='(')
//                 {
//                     s.pop();
//                 }
//                 else if(x=='}' && s.top()=='{')
//                 {
//                     s.pop();
//                 }
//                 else if(x==']' && s.top()=='[')
//                 {
//                     s.pop();
//                 }
//                 else return false;
//             }
//         }
//         if(s.empty()==false) return false;
//         return true;
//     }
// };
class Solution {
public:
   bool comp(char a, char b){
       if(a=='(' and b==')')
           return true;
       else if(a=='{' and b=='}')
           return true;
       else if(a=='[' and b==']')
           return true;
       else
           return false;
   }
    bool isValid(string s) {
         stack<char> st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
              st.push(s[i]);
            else if(s[i]==']' || s[i]=='}' || s[i]==')' )
            {
                if(st.empty() || !comp(st.top(),s[i]))
                    return false;
                else
                    st.pop();
            }
            //cout<<st.top();
        }
        //cout<<2<<" ";
        if(st.empty())
        {
            //cout<<1<<" ";
            return true;
        }   
        else return false;
    }
};