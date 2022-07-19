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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyless=new ListNode();
        ListNode* dummymore=new ListNode();
        ListNode* less=dummyless, *more=dummymore;
        while(head!=nullptr)
        {
            ListNode* temp=head->next;
            if(head->val < x)
            {
                less->next=head;
                less=less->next;
                head->next=nullptr;
            }
            else
            {
                more->next=head;
                more=more->next;
                head->next=nullptr;
            }
            head=temp;
        }
        less->next=dummymore->next;
        return dummyless->next;
    }
};