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
    ListNode* mergelist(ListNode *first, ListNode* second)
    {
        if(first==nullptr) return second;
        else if(second==nullptr) return first;
        ListNode *dummy=new ListNode();
        ListNode *last=dummy;
        while(first!=nullptr && second!=nullptr)
        {
            if(first->val < second->val)
            {
                last->next=first;
                last=first;
                first=first-> next;
                last->next=nullptr;
            }
            else
            {
                last->next=second;
                last=second;
                second=second->next;
                last->next=nullptr;
            }
        }
        if(second==nullptr)
            last->next=first;
        else
            last->next=second;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return nullptr;
        if(size==1) return lists[0];
        
        // O(n * k^2) approach merging 2 at a time. n is the avg length of each linked list
        // for(int i=1;i<size;i++)
        // {
        //     lists[i]=mergelist(lists[i-1],lists[i]); 
        // }
        // return lists[size-1];
        
        // Using 
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, 
        greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<size;i++)
        {
            if(lists[i]!=nullptr) pq.push({lists[i]->val,lists[i]});
        }
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int data=p.first;
            ListNode* temp=p.second;
            tail->next = new ListNode(data);
            tail=tail->next;
            temp=temp->next;
            if(temp!=nullptr)
            {
                pq.push({temp->val,temp});
            }
        }
        return dummy->next;
        
    }
};