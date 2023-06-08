
// Read editorial to understand
class Solution {
private:
    void helper(int i, string& num, int target, string& expr, vector<string>& ans,
    long long prevVal, long long prevNum, char prevOp,long long currNum) {
        int n = num.size();
        if(i == n) {
            if(prevVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        bool isDigit = false;
        if(expr.size()>=1 && (expr.back()>='0' && expr.back()<='9')) isDigit = true;
        expr+=num[i];
        currNum = currNum*10 + (num[i] - '0');
        if(i!=n-1 && (num[i]!='0' || (num[i] == '0' && isDigit == true))) {
            helper(i+1,num,target,expr,ans,prevVal,prevNum,prevOp,currNum);
        }
        if(prevOp == '*') {
            prevVal-=prevNum;
            prevNum = currNum*prevNum;
            prevVal+=prevNum;
            currNum=0;
        }
        else {
            if(prevOp == '+') {
                prevVal+=currNum;
                prevNum = currNum;
            }
            else {
                prevVal-=currNum;
                prevNum = -currNum;
            }
            currNum=0;
        }
        if(i == n-1) {
            helper(i+1,num,target,expr,ans,prevVal,prevNum,prevOp,currNum);
            expr.pop_back();
            return;
        }
        expr+='+';
        prevOp = '+';
        helper(i+1,num,target,expr,ans,prevVal,prevNum,prevOp,currNum);
        expr.back() = '-';
        prevOp = '-';
        helper(i+1,num,target,expr,ans,prevVal,prevNum,prevOp,currNum);
        expr.back() = '*';
        prevOp = '*';
        helper(i+1,num,target,expr,ans,prevVal,prevNum,prevOp,currNum);
        expr.pop_back();
        expr.pop_back();
    }
public:
    vector<string> addOperators(string num, int target) {
        string expr;
        vector<string> ans;
        helper(0,num,target,expr,ans,0,0,'+',0);
        return ans;
    }
};