class Solution {
public:
    vector<vector<int>>dp;
    int solve(int l,int r,string &s)
    {
        if(l>=r)return 0;
        int&ret=dp[l][r];
        if(~ret)return ret;
        if(s[l]==s[r])ret=solve(l+1,r-1,s);
        else ret=min(solve(l+1,r,s),solve(l,r-1,s))+1;
        return ret;
    }
    int minInsertions(string s) {
        dp=vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
        return solve(0,s.size()-1,s);
    }
};