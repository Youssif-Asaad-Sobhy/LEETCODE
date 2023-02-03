class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount,-1));
        return solve(0,0,dp,amount,coins);
    }
    int solve(int i,int cur,vector<vector<int>>&dp,int &amount,vector<int>&coins)
    {
        if(cur>amount)return 0;
        if(cur==amount)return 1;
        if(i==coins.size())return 0;
        int &ret=dp[i][cur];
        if(~ret)return ret;
        return ret=solve(i,cur+coins[i],dp,amount,coins)+solve(i+1,cur,dp,amount,coins);
    }
};