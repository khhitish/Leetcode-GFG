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
    ListNode* reverse(ListNode* node)
    {
        ListNode* ahead=node, *curr=nullptr, *prev=nullptr;
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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        ListNode* q=slow->next, *p=head;
        while(q!=nullptr)
        {
            if(p->val!=q->val)  return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};