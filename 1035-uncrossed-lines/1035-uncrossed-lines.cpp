class Solution {
public:
    int dp[501][501];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,nums1, nums2);
    }
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i==nums1.size()||j==nums2.size())return 0;
        int&ret=dp[i][j];
        if(~ret)return ret;
        int cnt=0;
        cnt=solve(i+1,j,nums1, nums2);
        cnt=max(cnt,solve(i,j+1,nums1, nums2));
        if(nums1[i]==nums2[j])
            cnt=max(cnt,solve(i+1,j+1,nums1, nums2)+1);
        return ret=cnt;
    }
};