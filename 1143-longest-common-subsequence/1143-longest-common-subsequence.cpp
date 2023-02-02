class Solution {
public://73
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp=vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2);
    }
    int solve(int i,int j,string &s,string &ss)
    {
        if(i==s.size())return 0;
        if(j==ss.size())return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        if(s[i]==ss[j])ret=1+solve(i+1,j+1,s,ss);
        ret=max(ret,solve(i+1,j,s,ss));
        ret=max(ret,solve(i,j+1,s,ss));
        return ret;
    }
};