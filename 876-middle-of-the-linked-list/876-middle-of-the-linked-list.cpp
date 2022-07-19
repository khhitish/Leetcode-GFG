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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* fast=head, *slow=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        } while(fast!=nullptr && fast->next!=nullptr);
        return slow;
    }
};