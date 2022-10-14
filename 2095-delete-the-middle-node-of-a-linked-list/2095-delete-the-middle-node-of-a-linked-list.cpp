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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* slow = head, *fast = head,*trail=nullptr;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            trail=slow;
            slow = slow->next;
        }
        trail->next = slow->next;
        delete(slow);
        return head;
    }
};