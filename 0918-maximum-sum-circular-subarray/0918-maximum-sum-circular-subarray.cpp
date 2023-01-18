class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int l=0,r=INT_MAX,ans=INT_MIN,temp=0;
        vector<int>dp(nums.size(),0),dpp(nums.size(),0);
        r=l=ans=dp[0]=dpp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]); 
            ans=max(ans,dp[i]);
            dpp[i]=min(dpp[i-1]+nums[i],nums[i]); 
            r=min(r,dpp[i]);
            l+=nums[i];
        }
        return (r==l?ans:max(ans,l-r));
    }
};