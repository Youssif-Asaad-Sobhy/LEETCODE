class Solution {
public:
    int dp[2][5005];
    int solve(int i,bool tr,vector<int>&v)
    {
        if(i>=v.size())return 0;
        int &ret=dp[tr][i];
        if(~ret)return ret;
        int leave,take;
        leave=solve(i+1,tr,v);
        if(tr)take=-v[i]+solve(i+1,!tr,v);
        else take=v[i]+solve(i+2,!tr,v);
        return ret=max(leave,take);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(0,1,prices);
    }
};