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
private:
    ListNode* addTwoNos1(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy= new ListNode();
        ListNode* curr = dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry>0)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            curr->next = new ListNode(sum%10);
            curr=curr->next;
            carry = sum/10;
        }
        return dummy->next;
    }
    
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr, *curr=nullptr, *ahead=head;
        while(ahead!=nullptr)
        {
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            curr->next=prev;
        }
        return curr;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* f=reverse(l1);
        ListNode* s=reverse(l2);
        ListNode* res = addTwoNos1(f,s);
        return reverse(res);
    }
};