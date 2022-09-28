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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* two pass finding length then deleting
        int size=0;
        ListNode *p=head;
        while(p!=nullptr)
        {
            size++;
            p=p->next;
        }
        int reqp=size-n;
        p=head;
        if(size==n)//deleting head node special case
        {
            
            head=head->next;
            delete p;
            return head;
        }
        while(reqp-1>0)//going to prev node and deleting the required
        {
            p=p->next;
            reqp--;
        }
        ListNode *q=p->next;
        p->next=q->next;
        delete q;
        return head;
        */
        //one pass https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8804/Simple-Java-solution-in-one-pass
        ListNode *p=head, *q=head;
        while(n--)
        {
            p=p->next;
        }
        if(p==nullptr)
        {
            head=q->next;
            delete q;
            return head;
        }
        else
        {
            while(p->next!=nullptr)
            {
                p=p->next;
                q=q->next;
            }
            ListNode *temp=q->next;
            q->next=temp->next;
            delete temp;
            return head;
        }
    }
};