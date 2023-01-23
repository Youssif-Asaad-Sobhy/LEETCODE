class Solution {
public:
    int dp[2][50005],x;
    int solve(int i,bool tr,vector<int>&v)
    {
        if(i>=v.size())return 0;
        int &ret=dp[tr][i];
        if(~ret)return ret;
        int leave,take;
        leave=solve(i+1,tr,v);
        if(tr)take=-v[i]-x+solve(i+1,!tr,v);
        else take=v[i]+solve(i+1,!tr,v);
        return ret=max(leave,take);
    }
    int maxProfit(vector<int>& prices,int fee) {
        memset(dp,-1,sizeof dp);
        x=fee;
        return solve(0,1,prices);
    }
};