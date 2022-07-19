/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* curr=head;
        while(curr!=nullptr)
        {
            len++;
            curr=curr->next;
        }
        int num;
        int extra;
        if(k<=len)
        {
            num=len/k;
            extra=len%k;
        }
        else
        {
            num=1;
            extra=0;
        }
        vector<ListNode*> ans;
        curr=head;
        //cout<<num<<" "<<extra<<endl;
        while(curr!=nullptr)
        {
            ans.push_back(curr);
            int cnt=1;
            int lim = extra>0? num+1 : num;
            while(cnt < lim)
            {
                curr=curr->next;
                cnt++;
            }
            ListNode* temp = curr->next;
            curr->next=nullptr;
            curr=temp;
            if(extra>0)extra--;
        }
        while(ans.size()<k)
        {
            ans.push_back(nullptr);
        }
        return ans;
    }
};