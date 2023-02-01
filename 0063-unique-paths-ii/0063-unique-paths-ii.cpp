class Solution {
public:
    int n,m;
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
            n=Grid.size(),m=Grid[0].size();
            vector<vector<int>>dp(n+5,vector<int>(m+5,-1));
            return solve(0,0,dp,Grid);
    }
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(!(i<n&&j<m)||(i<n&&j<m&&grid[i][j]==1))return 0;
        if(i==n-1&&j==m-1)return 1;
        int &ret=dp[i][j];
        if(~ret)return ret;
        return ret=solve(i+1,j,dp,grid)+solve(i,j+1,dp,grid);
    }
};