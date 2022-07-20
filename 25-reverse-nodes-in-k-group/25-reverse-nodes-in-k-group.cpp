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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i=0;i<k;i++)
        {
            if(temp==nullptr) return head;
            temp=temp->next;
        }
        ListNode* ahead=head, *curr=nullptr, *prev=nullptr;
        for(int i=0;i<k;i++)
        {
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            curr->next=prev;
        }
        head->next = reverseKGroup(ahead,k);
        return curr;
    }
};