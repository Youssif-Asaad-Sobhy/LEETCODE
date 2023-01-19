class Solution {
public:
    const int n=10005;
    vector<int>dp,nums;
    bool solve(int idx)
    {
        if(idx==nums.size()-1)return 1;
        int &ret=dp[idx];
        if(~ret)return ret;
        ret=0;
        for(int i=min((int)idx+nums[idx],(int)nums.size()-1);i>idx;i--)
        {
            ret=solve(i);
            if(ret==1)return ret;
        }
        return ret;
    }
    bool canJump(vector<int>& num) {
        nums=num;
        dp=vector<int>(n,-1);
        return solve(0);
    }
};