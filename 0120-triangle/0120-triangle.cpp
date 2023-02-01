class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp)
    {
        if(i==v.size())return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        return ret=min(solve(i+1,j,v,dp),solve(i+1,j+1,v,dp))+v[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return solve(0,0,triangle,dp);
    }
};