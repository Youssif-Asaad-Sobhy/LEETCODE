class Solution {
public:
    int dp[325];
    string ss;
    bool solve(int i,vector<string>&v)
    {
        if(i>=ss.size())return 1;
        int &ret=dp[i];
        if(~ret)return ret;
        ret=0;
        string temp;
        for(int j=1;j<=20;j++)
        {
            temp=ss.substr(i,j);
            if(binary_search(v.begin(),v.end(),temp))ret|=solve(i+j,v);
            if(ret)return ret;
        }
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof dp);
        ss=s;
        return solve(0,wordDict);
    }
};