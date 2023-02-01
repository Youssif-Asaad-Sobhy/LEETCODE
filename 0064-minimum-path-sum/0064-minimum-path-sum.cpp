class Solution {
public:
    int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+5,vector<int>(m+5,-1));
        return solve(0,0,dp,grid);
    }
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(!(i<n&&j<m))return 30000;
        if(i==n-1&&j==m-1)return grid[i][j];
        int &ret=dp[i][j];
        if(~ret)return ret;
        return ret=min(solve(i+1,j,dp,grid),solve(i,j+1,dp,grid))+grid[i][j];
    }
};