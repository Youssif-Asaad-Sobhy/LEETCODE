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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>v;
        ListNode*ans=head;
        while(head!=NULL)
        {
            v.push_back(head);
            head=head->next;
        }
        swap(v[k-1]->val,v[v.size()-k]->val);
        return ans;
    }
};