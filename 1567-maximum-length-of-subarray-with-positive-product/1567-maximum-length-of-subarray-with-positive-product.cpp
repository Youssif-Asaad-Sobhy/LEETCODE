class Solution {
public:
    int getMaxLen(vector<int>& v) {
        vector<vector<int>>dp(2,vector<int>(v.size()+1));//0->maxnegative,1->maxpostive
        int ans=0;
        bool neg=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                dp[0][i+1]=dp[1][i+1]=0;
            }
            else if(v[i]<0)
            {
                dp[0][i+1]=dp[1][i]+1;
                dp[1][i+1]=dp[0][i];
                if(dp[1][i+1]!=0)
                    dp[1][i+1]++;
            }
            else
            {
                dp[1][i+1]=dp[1][i]+1;
                if(dp[0][i]!=0)
                    dp[0][i+1]=dp[0][i]+1;
                else
                    dp[0][i+1]=dp[0][i];
            }
            ans=max({ans,dp[1][i+1]});
        }
        
        return ans;
    }
};