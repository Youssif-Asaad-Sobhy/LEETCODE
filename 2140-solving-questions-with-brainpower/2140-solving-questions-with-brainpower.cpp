class Solution {
public:
    long long dp[100005];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof dp);
        return solve(0,questions);
    }
    long long solve(int i,vector<vector<int>>& q)
    {
        if(i>=q.size())return 0;
        long long &ret=dp[i];
        if(~ret)return ret;
        return ret=max(solve(i+q[i][1]+1,q)+q[i][0],solve(i+1,q));
    }
};