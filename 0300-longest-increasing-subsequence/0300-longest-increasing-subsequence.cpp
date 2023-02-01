class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(-100000);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(0,nums.size()-1,dp,nums);
    }
    int solve(int i,int lst,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(i==nums.size())return 0;
        int &ret=dp[i][lst];
        if(~ret)return ret;
        ret=0;
        if(nums[i]>nums[lst])ret=solve(i+1,i,dp,nums)+1;
        return ret=max(ret,solve(i+1,lst,dp,nums));
    }
};