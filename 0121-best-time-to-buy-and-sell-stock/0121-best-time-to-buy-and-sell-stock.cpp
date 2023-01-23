class Solution {
public:
    vector<vector<int>>dp;
    vector<bool>vis;
    int x;
    int solve(int i,bool tr,vector<int>&v)
    {
        if(i==v.size())return 0;
        int &ret=dp[tr][i];
        if(~ret)return ret;
        int leave=solve(i+1,tr,v);
        if(tr)return ret=max(leave,solve(i+1,!tr,v)-v[i]);
        else return ret=max(leave,v[i]);
    }
    int maxProfit(vector<int>& prices) {
        dp=vector<vector<int>>(2,vector<int>(prices.size(),-1));
        int ans=solve(0,1,prices);
        return ans;
    }
};