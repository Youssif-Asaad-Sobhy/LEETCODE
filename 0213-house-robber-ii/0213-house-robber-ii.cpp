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
        int x=nums.back();
        nums.pop_back();
        dp=vector<int>(nums.size(),-1);
        int cnt=solve(0,-2,nums);
        nums.push_back(x);
        nums[0]=INT_MIN;
        dp=vector<int>(nums.size(),-1);
        cnt=max(solve(0,-2,nums),cnt);
        return max(cnt,x);
    }
};