class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> dp(nums.size(),vector<int>(1001,0));
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;--j){
                int dif = nums[i]-nums[j];
                dp[i][dif+500] = max(dp[i][dif+500],dp[j][dif+500]+1);
                ans = max(dp[i][dif+500],ans);
            }
        }
        return ans+1;
    }
};