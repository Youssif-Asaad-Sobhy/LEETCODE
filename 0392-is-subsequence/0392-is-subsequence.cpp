class Solution {
public:
    vector<vector<int>>dp;
    bool isSubsequence(string s, string t) {
        dp=vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t);
    }
    bool solve(int i,int j,string &s,string &t)
    {
        if(i==s.size())return 1;
        if(j==t.size())return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        if(s[i]==t[j])ret|=solve(i+1,j+1,s,t);
        ret|=solve(i,j+1,s,t);
        return ret;
    }
};