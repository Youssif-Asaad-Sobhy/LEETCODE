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
    vector<int>sums;
    void solve(TreeNode* root,int lvl)
    {
        if(root==NULL)return;
        if(sums[lvl]==INT_MIN)sums[lvl]=0;
        sums[lvl]+=root->val;
        solve(root->left,lvl+1);
        solve(root->right,lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        sums=vector<int>(10002,INT_MIN);
        solve(root,1);
        int mx=INT_MIN,ans=0;
        for(int i=1;i<10002;i++)if(sums[i]>mx)mx=sums[i],ans=i;
        return ans;
    }
};