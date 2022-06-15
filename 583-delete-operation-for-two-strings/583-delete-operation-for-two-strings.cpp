class Solution {
public:
    int minDistance(string s, string ss) {
    int i,j;
    vector<vector<int>>dp(s.size()+1,(vector<int>(ss.size()+1,0)));
    for(i=0;i<=s.length();i++)
    {
        for(j=0;j<=ss.length();j++)
        {
            if(i==0||j==0)
                continue;
            if(s[i-1]==ss[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return s.size()+ss.size()-2*dp[s.length()][ss.length()];
    }
};