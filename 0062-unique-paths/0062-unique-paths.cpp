class Solution {
public:
    int nn,mm;
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+5,vector<int>(n+5,-1));
        nn=n,mm=m;
        return solve(1,1,dp);
    }
    int solve(int i,int j,vector<vector<int>>&dp)
    {
        if(i>mm||j>nn)return 0;
        if(i==mm&&j==nn)return 1;
        int &ret=dp[i][j];
        if(~ret)return ret;
        return ret=solve(i+1,j,dp)+solve(i,j+1,dp);
    }
};