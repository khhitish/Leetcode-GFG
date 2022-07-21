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
    ListNode* reversell(ListNode* head, int k)
    {
        ListNode* ahead=head, *curr=nullptr, *prev=nullptr;
        while(k--)
        {
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            curr->next=prev;
        }
        head->next=ahead;
        return curr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* curr=dummy;
        for(int i=0;i<left-1;i++)
        {
            curr=curr->next;
        }
        curr->next=reversell(curr->next,right-left+1);
        return dummy->next;
    }
};