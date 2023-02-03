class Solution {
public:
    int dp[13][10005],x;
    int solve(int i,long long cur,vector<int>&v)
    {
        if(cur==x)return 0;
        else if(cur>x)return 10001;
        else if(i==v.size())return 10001;
        int &ret=dp[i][cur];
        if(~ret)return ret;
        int take,leave;
        leave=solve(i+1,cur,v);
        take=1+solve(i,cur+v[i],v);
        return ret=min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        x=amount;
        int ans=solve(0,0,coins);
        return (ans==10001?-1:ans);
    }
};