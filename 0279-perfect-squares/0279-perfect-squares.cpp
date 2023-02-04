class Solution {
public:
    vector<int>v;
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++)
        {
            v.push_back(i*i);
        }
        vector<vector<int>>dp(v.size(),vector<int>(n+5,-1));
        return solve(0,0,dp,v,n);
    }
    int solve(int i,int cur,vector<vector<int>>&dp,vector<int>&v,int&n)
    {
        if(cur>=n)return (cur==n?0:10000);
        if(i==v.size())return 10000;
        int &ret=dp[i][cur];
        if(~ret)return ret;
        return ret=min(1+solve(i,cur+v[i],dp,v,n),solve(i+1,cur,dp,v,n));
    }
};