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
// https://leetcode.com/problems/add-two-numbers-ii/discuss/687339/Java-O(N)-solution-with-follow-up-question-no-recursion-no-stacks
class Solution {
private:
//     ListNode* addTwoNos1(ListNode* l1, ListNode* l2)
//     {
//         ListNode* dummy= new ListNode();
//         ListNode* curr = dummy;
//         int carry=0;
//         while(l1!=nullptr || l2!=nullptr || carry>0)
//         {
//             int sum=0;
//             if(l1)
//             {
//                 sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2)
//             {
//                 sum+=l2->val;
//                 l2=l2->next;
//             }
//             sum+=carry;
//             curr->next = new ListNode(sum%10);
//             curr=curr->next;
//             carry = sum/10;
//         }
//         return dummy->next;
//     }
    
    
//     ListNode* reverse(ListNode* head)
//     {
//         ListNode* prev=nullptr, *curr=nullptr, *ahead=head;
//         while(ahead!=nullptr)
//         {
//             prev=curr;
//             curr=ahead;
//             ahead=ahead->next;
//             curr->next=prev;
//         }
//         return curr;
//     }
    
    int sizeofll(ListNode* head)
    {
        int size=0;
        while(head!=nullptr)
        {
            head=head->next;
            size++;
        }
        return size;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // // reversing input lists and adding like addtwonumbers1 question
        // ListNode* f=reverse(l1);
        // ListNode* s=reverse(l2);
        // ListNode* res = addTwoNos1(f,s);
        // return reverse(res);
        
        int s1=sizeofll(l1), s2=sizeofll(l2);
        ListNode* prev=nullptr, *curr=nullptr;
        while(l1!=nullptr && l2!=nullptr)
        {
            int sum=0;
            if(s1==s2)
            {
                sum+=l1->val + l2->val;
                l1=l1->next;
                l2=l2->next;
                s1--;
                s2--;
            }
            else if(s1>s2)
            {
                sum+=l1->val;
                l1=l1->next;
                s1--;
            }
            else
            {
                sum+=l2->val;
                l2=l2->next;
                s2--;
            }
            curr=new ListNode(sum);
            curr->next=prev;
            prev=curr;
        }
        int carry=0;
        ListNode* ahead=curr;
        curr=nullptr; prev=nullptr;
        while(ahead!=nullptr)
        {
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            int sum = curr->val + carry;
            curr->val = sum%10;
            carry=sum/10;
            curr->next=prev;
        }
        if(carry>0)
        {
            ListNode* res = new ListNode(carry);
            res->next=curr;
            return res;
        }
        return curr;
    }
};