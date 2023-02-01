class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp)
    {
        if(i==v.size())return 0;
        if(j<0||j>=v[0].size())return 100000;
        int &ret=dp[i][j];
        if(~ret)return ret;
        return ret=min({solve(i+1,j-1,v,dp),solve(i+1,j,v,dp),solve(i+1,j+1,v,dp)})+v[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int cnt=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        cnt=min(solve(0,i,matrix,dp),cnt);
        }
        return cnt;
    }
};