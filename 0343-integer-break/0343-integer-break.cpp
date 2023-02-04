class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+50);
        dp[1]=dp[0]=dp[2]=1;
        if(n==3)return 2;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i]=max(dp[i],dp[j]*(i-j));
            }
        }
        return dp[n];
    }
};