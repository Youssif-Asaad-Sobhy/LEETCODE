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
        ListNode* tmp=head;
        int n=0;
        while(tmp)
            tmp=tmp->next,n++;
        int i=0;
        while(head)
        {
            if(i>=n/2)return head;
            i++;
            head=head->next;
        }
        return head;
        
    }
};