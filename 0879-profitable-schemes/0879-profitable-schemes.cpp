class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int i,int cn,int cm,vector<int>&group,vector<int>&profit)
    {
        if(cm<0)cm=0;
        if(cn<0)return 0;
        if(i==group.size())return cm==0;
        int &ret=dp[i][cn][cm];
        if(~ret)return ret;
        return ret=(1LL*solve(i+1,cn-group[i],cm-profit[i],group,profit)+solve(i+1,cn,cm,group,profit))%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp=vector<vector<vector<int>>>(profit.size(),vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(0,n,minProfit,group,profit);
    }
};