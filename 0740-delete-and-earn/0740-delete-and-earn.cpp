class Solution {
public:
    vector<int>dp,fre;
    vector<bool>vis;
    int solve(int idx)
    {
        if(idx==fre.size())return 0;
        int& ret=dp[idx];
        if(~ret)return ret;
        int take=0,leave=0;
        if(!vis[idx]&&fre[idx])
        {
            vis[idx+1]=vis[idx-1]=1;
            take=solve(idx+2)+fre[idx]*idx;
            vis[idx+1]=vis[idx-1]=0;
        }
        leave=solve(idx+1);
        return ret=max(take,leave);
    }
    int deleteAndEarn(vector<int>& nums) {
        dp=vector<int>(10005,-1);
        fre=vector<int>(10005,0);
        vis=vector<bool>(20005);
        for(auto it:nums){fre[it]++;}
        return solve(1);
    }
};