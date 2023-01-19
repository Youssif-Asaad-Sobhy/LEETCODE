class Solution {
public:
    vector<int>dp;
    int solve(int idx,int ol,vector<int>& v)
    {
        if(idx>=v.size())return 0;
        int& ret=dp[idx];
        if(~ret)return ret;
        ret=solve(idx+2,idx,v)+v[idx];
        ret=max(ret,solve(idx+1,ol,v));
        return ret;
    }
    int rob(vector<int>& nums) {
        dp=vector<int>(nums.size(),-1);
        return solve(0,-2,nums);
    }
};