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
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(q.size())
        {
            root=q.front();
            q.pop();
            v.push_back(root->val);
            if(root->right)
                q.push(root->right);
            if(root->left)
                q.push(root->left);
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            ans=min(ans,abs(v[i]-v[i+1]));
        }
        return ans;
    }
};