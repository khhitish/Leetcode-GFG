/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            // // reusing same ll
            // ListNode *p = l1, *q = l2;
            // ListNode *tp = p;	//trailing pointer
            // int carry = 0;
            // while (p != nullptr && q != nullptr)
            // {
            //     int temp = p->val + q->val + carry;
            //     p->val = temp % 10;
            //     carry = temp / 10;
            //     tp = p;
            //     p = p->next;
            //     q = q->next;
            // }
            // if (q == nullptr && p != nullptr)	//if q is smaller sized
            // {
            //     while (carry != 0 && p != nullptr)
            //     {
            //         int temp = p->val + carry;
            //         p->val = temp % 10;
            //         carry = temp / 10;
            //         tp = p;
            //         p = p->next;
            //     }
            // }
            // else if (p == nullptr && q != nullptr)	// if p is smaller sized
            // {
            //     tp->next = q;
            //     while (carry != 0 && q != nullptr)
            //     {
            //         int temp = q->val + carry;
            //         q->val = temp % 10;
            //         carry = temp / 10;
            //         tp = q;
            //         q = q->next;
            //     }
            // }
            // if (carry > 0)
            // {
            //     ListNode *t = new ListNode(carry);
            //     tp->next = t;
            // }
            // return l1;
            
            // creating new ll
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
};