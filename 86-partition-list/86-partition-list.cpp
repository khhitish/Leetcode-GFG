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
        ListNode* dummyless=new ListNode(), *dummymore = new ListNode();
        ListNode* currless=dummyless, *currmore=dummymore;
        ListNode* curr=head;
        while(curr!=nullptr)
        {
            ListNode* temp = curr->next;
            if(curr->val < x)
            {
                currless->next = curr;
                currless=currless->next;
                currless->next=nullptr;
            }
            else
            {
                currmore->next = curr;
                currmore = currmore->next;
                currmore->next=nullptr;
            }
            curr=temp;
        }
        currless->next = dummymore->next;
        return dummyless->next;
    }
};