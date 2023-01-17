class Solution {
public:
    string s;
    int minFlipsMonoIncr(string ss) {
        s=ss;
        vector<vector<int>>dp(s.size(),vector<int>(2,-1));
        return solve(0,0,dp);
    }
    int solve(int i,bool tr,vector<vector<int>>&dp)
    {
        if(i==s.size())return 0;
        int &ret=dp[i][tr];
        if(~ret)return ret;
        if(!tr&&s[i]=='0')
        {
            ret=solve(i+1,!tr,dp)+1;
            ret=min(ret,solve(i+1,tr,dp));
        }
        else if(!tr&&s[i]=='1')
        {
            ret=solve(i+1,!tr,dp);
            ret=min(ret,solve(i+1,tr,dp)+1);
        }
        else if(tr&&s[i]=='1')
            ret=solve(i+1,tr,dp);
        else ret=solve(i+1,tr,dp)+1;
        return ret;
    }
};