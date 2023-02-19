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
    vector<vector<int>>ans;
    void solve(TreeNode*root,int idx)
    {
        if(root==NULL)return;
        if(idx>ans.size())
        {
            vector<int>v={root->val};
            ans.push_back(v);
        }
        else ans[idx-1].push_back(root->val);
        solve(root->left,idx+1);
        solve(root->right,idx+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ans.clear();
        solve(root,1);
        for(int i=0;i<ans.size();i++)
        {
            if(i&1)reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};