class Solution {
public:
    const int n=10005;
    vector<int>dp,nums;
    int solve(int idx)
    {
        if(idx==nums.size()-1)return 0;
        int &ret=dp[idx];
        if(~ret)return ret;
        int ans=100000;
        for(int i=min((int)idx+nums[idx],(int)nums.size()-1);i>idx;i--)
        {
            ans=min(solve(i)+1,ans);
        }
        return ret=ans;
    }
    int jump(vector<int>& num) {
        nums=num;
        dp=vector<int>(n,-1);
        return solve(0);
    }
};