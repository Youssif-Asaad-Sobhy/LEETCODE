class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long>dp(target+1050);
        dp[0]=1;
        long long mod=1e15+7;
        for(int j=0;j<=target;j++)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(j-nums[i]<0)continue;
                dp[j]+=dp[j-nums[i]];
                dp[j]%=mod;
            }
        }
        return dp[target];
    }
};
/**
    
    
    
    **/