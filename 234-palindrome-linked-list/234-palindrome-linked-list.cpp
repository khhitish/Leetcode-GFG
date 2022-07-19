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
    ListNode* reverse(ListNode* head)
    {
        ListNode* ahead = head, *curr = nullptr, *prev=nullptr;
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
        if(head->next==nullptr) return head;
        ListNode* slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode* first=head, *second=slow->next;
        while(second!=nullptr)
        {
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};