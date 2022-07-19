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
    ListNode* swapPairs(ListNode* head) {
        // if(head==nullptr || head->next==nullptr) return head;
        // ListNode* second=head->next;
        // ListNode* p=swapPairs(second->next);
        // head->next=p;
        // second->next=head;
        // return second;
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* first=head, *second=head->next, *prev=nullptr;
        head=second;
        while(first!=nullptr && second!=nullptr)
        {
            ListNode* temp= second->next;
            first->next=temp;
            second->next=first;
            if(prev!=nullptr) prev->next = second;
            prev=first;
            first=temp;
            if(temp!=nullptr) second=temp->next; 
        }
        return head;
    }
};