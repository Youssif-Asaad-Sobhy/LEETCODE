class Solution {
public:

    int solve(int idx,string& s,vector<int>&dp)
    {
        if(idx==s.size())return 1;
        int& ret=dp[idx];
        if(~ret)return ret;
        int cnt=0;
        if(s[idx]=='0')return 0;
        cnt=solve(idx+1,s,dp);
        if(idx<s.size()-1)
        {
            if(s[idx]=='2'&&s[idx+1]<='6')
                cnt+=solve(idx+2,s,dp);
            else if(s[idx]=='1')
                cnt+=solve(idx+2,s,dp);
        }
        return ret=cnt;
    }
    int numDecodings(string s) {
        vector<int>dp(105,-1);
        return solve(0,s,dp);
    }
};