/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(q.size())
        {
            root=q.front();
            q.pop();
            if(root==NULL)continue;
            v.push_back(root->val);
            q.push(root->right);
            q.push(root->left);
        }
        sort(v.begin(),v.end());
        int cnt=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            cnt=min(cnt,abs(v[i]-v[i+1]));
        }
        return cnt;
    }
};