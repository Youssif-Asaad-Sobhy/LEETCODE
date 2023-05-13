class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+5);
        dp[0]=1;
        int ans=0,mod=1e9+7;
        for(int i=0;i<=high;i++)
        {
            if(dp[i])
            {
                if(i+zero<=high)dp[i+zero]+=dp[i],dp[i+zero]%=mod;
                if(i+one<=high)dp[i+one]+=dp[i],dp[i+one]%=mod;
            }
            if(i>=low)ans+=dp[i],ans%=mod;
        }
        return ans;
    }
};