class Solution {
public:
    int mx1=0,mx2=0;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        for(int i=0;i<ages.size();i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        v.push_back({INT_MAX,INT_MAX});
        sort(v.rbegin(),v.rend());
        vector<vector<int>>dp(v.size()+5,vector<int>(v.size()+5,-1));
        return solve(1,0,v,dp);
    }
    int solve(int i,int prev,vector<pair<int,int>>&v,vector<vector<int>>&dp)
    {
        if(i==v.size())return 0;
        int&ret=dp[i][prev];
        if(~ret)return ret;
        int cnt=0;
        if(v[i].second<=v[prev].second)cnt=solve(i+1,i,v,dp)+v[i].second;
        cnt=max(cnt,solve(i+1,prev,v,dp));
        return ret=cnt;
    }
};