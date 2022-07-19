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
    ListNode* reverserecur(ListNode* curr, ListNode* &head)
    {
        if(curr==nullptr) return nullptr;
        if(curr->next==nullptr)
        {
            head=curr;
            return curr;
        }
        ListNode* ahead = reverserecur(curr->next, head);
        ahead->next=curr;
        curr->next=nullptr;
        return curr;  
    }
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev=nullptr, *curr=nullptr, *ahead=head;
        // while(ahead!=nullptr)
        // {
        //     prev=curr;
        //     curr=ahead;
        //     ahead=ahead->next;
        //     curr->next = prev;
        // }
        // return curr;
        ListNode* newhead=nullptr;
        reverserecur(head,newhead);
        return newhead;
    }
};